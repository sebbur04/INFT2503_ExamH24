//
// Created by Sebastian E Burmo on 10/10/2025.
//
// Based on: https://gitlab.com/ntnu-iini4003/examples6/-/blob/master/example6.cpp

#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_context &io_context) : socket(io_context) {}
  };

  boost::asio::io_context io_context;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  // Handles HTTP GET requests and sends valid HTTP responses
  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read until end of HTTP headers
    async_read_until(connection->socket, *read_buffer, "\r\n\r\n", [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());
        string request_line;
        getline(read_stream, request_line);
        // Set statements on the HTTP website based on the string body, and create the full HTTP response for the page
        string response;

        // Case A - localhost:8080 -> main page --> "Dette er hovedsiden"
        if (request_line.find("GET / HTTP/1.1") != string::npos) {
          string body = "Dette er hovedsiden";
          response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + to_string(body.size()) + "\r\n\r\n" + body;
        }

        // Case B - localhost:8080/en_side --> "Dette er en side"
        else if (request_line.find("GET /en_side HTTP/1.1") != string::npos) {
          string body = "Dette er en side";
          response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + to_string(body.size()) + "\r\n\r\n" + body;
        }

        // Case C - localhost:8080/(Kan være hva som helst siden det er en else statement) --> "404 Not Found"
        else {
          string body = "404 Not Found";
          response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: " + to_string(body.size()) + "\r\n\r\n" + body;
        }

        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());
        write_stream << response;

        // Write HTTP response and close connection
        async_write(connection->socket, *write_buffer, [connection, write_buffer](const boost::system::error_code &ec, size_t) {
          // Connection closes after response
        });
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed
    auto connection = make_shared<Connection>(io_context);
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  // Set the Echoserver to listen on port 8080, so you can connect with localhost 8080
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_context, endpoint) {}

  void start() {
    accept();
    io_context.run();
  }
};

int main() {
  EchoServer echo_server;

  cout << "Starting echo server" << endl
       << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection"<< endl
       << "For å teste oppgaven: Åpne i nettleser http://localhost:8080 eller http://localhost:8080/en_side eller et tilfeldig directory for 404 melding " << endl;

  echo_server.start();
}

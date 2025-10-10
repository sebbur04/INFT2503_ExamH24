//
// Created by Sebastian E Burmo on 10/10/2025.
// Based on opp2.cpp in OBL5 with changes like ChessBoardPrint class and lambda functions for callbacks
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE, BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}
    Color color;
    string color_string() const {
      return color == Color::WHITE ? "white" : "black";
    }
    virtual string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color){}
    string type() const override { return color_string() + " king"; }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}
    string type() const override { return color_string() + " knight"; }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
  };

  ChessBoard() {
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  vector<vector<unique_ptr<Piece>>> squares;

  // Declaring callback objects in chesssboard class, where I can set lamda functions
  function<void(const Piece&, const string&, const string&)> on_piece_move;
  function<void(const Piece&, const string&)> on_piece_removed;
  function<void(const Piece&, const string&, const string&)> on_piece_move_invalid;
  function<void(const string&)> on_piece_move_missing;
  function<void(const King&)> on_lost_game;
  function<void()> after_piece_move;

  // Add callbacks, change from the previous code in OBL5
  bool move_piece(const string &from, const string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move) on_piece_move(*piece_from, from, to);
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (on_piece_removed) on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              if (on_lost_game) on_lost_game(*king);
          } else {
            if (on_piece_move_invalid) on_piece_move_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = move(piece_from);
        if (after_piece_move) after_piece_move();
        return true;
      } else {
        if (on_piece_move_invalid) on_piece_move_invalid(*piece_from, from, to);
        return false;
      }
    } else {
      if (on_piece_move_missing) on_piece_move_missing(from);
      return false;
    }
  }

  void print(ostream &os) const {
    for(int row = 7; row >= 0; row--) {
      os << (row + 1) << " ";
      for(int col = 0; col < 8; col++) {
        auto &piece = squares[col][row];
        if (piece) {
          // Vis K+farge for king, N+farge for knight
          string type_str = piece->type();
          if (type_str.find("king") != string::npos) {
            os << (piece->color == Color::WHITE ? "WK" : "BK");
          } else if (type_str.find("knight") != string::npos) {
            os << (piece->color == Color::WHITE ? "WN" : "BN");
          }
          os << " ";
        } else {
          os << " . "; // Tom rute uten brikke
        }
      }
      os << "\n";
    }
    os << "  a  b  c  d  e  f  g  h "; // Rute bokstavene nederst på brettet
  }
};

ostream &operator<<(ostream &os, const ChessBoard &board) {
  board.print(os);
  return os;
}

// definere funksjonsobjektene til ChessBoard instansen ved hjelp av lambda uttrykk.
//Utskriften av sjakkbrettet etter et sjakktrekk skal også foregå i ChessBoardPrint
class ChessBoardPrint {
  ChessBoard &board;
public:
  ChessBoardPrint(ChessBoard &b) : board(b) {
    board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.type() << " is being removed from " << square << endl;
    };
    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };
    board.on_piece_move_missing = [](const string &square) {
      cout << "no piece at " << square << endl;
    };
    board.on_lost_game = [](const ChessBoard::King &king) {
      cout << king.color_string() << " lost the game" << endl;
    };
    board.after_piece_move = [this]() { this->print_board(); };
  }
  void print_board() {
    cout << board << endl;
  }
};

int main() {
  ChessBoard board;
  ChessBoardPrint print(board); // getting the ChessBoardPrint, where the print is handled in the class

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "Brikker" << endl;
  cout << "BN equals a Black Knight" << endl;
  cout << "BK equals a Black King" << endl;
  cout << "WN equals a White Knight" << endl;
  cout << "WK equals a White King" << endl;

  cout << "A simulated game:" << endl;
  print.print_board();
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}

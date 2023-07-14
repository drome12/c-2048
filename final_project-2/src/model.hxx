#pragma once

#include <ge211.hxx>

class Model
{



public:
    Model();
    using Position = ge211::Posn<int>;
    using Rectangle = ge211::Rect<int>;


    bool hasEmptySpace() const;
    int get_piece_at_position(int i, int j) const;
    int& tile_at_position(int i,int j);
    void get_highest_tile();
    int score() const;
    bool checkHorizontalGameOver();
    bool checkVerticalGameOver();
    void isGameOver() ;
    void isGameWon() ;
    bool isGameStarted() const;
    void addPiece();
    ge211::Posn<int> generate_unoccupied_position() const;
    void newGame() ;
    void advance_game(char cardinal_cord);
    void moveLeft() ;
    void moveRight() ;
    bool game_over() const;
    bool game_won() const;
    void moveUp() ;
    void moveDown() ;


private:
    int board_[4][4];
    bool made_move_;
    int score_;
    bool game_over_;
    bool game_won_;
    bool game_started_;









};
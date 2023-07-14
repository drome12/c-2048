#include "model.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

struct Test_access
{
    Model& model;
    explicit Test_access(Model&);
    void move_up(){
        return model.moveUp();
    }
    void move_down(){
        return model.moveDown();
    }
    void move_right(){
        return model.moveRight();
    }
    void move_left(){
        return model.moveLeft();
    }
    void game_won(){
        return model.isGameWon();
    }

    void game_lost(){
        return model.isGameOver();
    }
    int high_score(){
        model.get_highest_tile();
        return model.score();
    }
    int tile_at(int i, int j){
        return model.get_piece_at_position(i,j);
    }
    int& tile_at_2(int i, int j){
        return model.tile_at_position(i,j);
    }

    void set_position(int row, int col, int val){
        model.tile_at_position(row,col) = val;

    };

};

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//

TEST_CASE("easy win by merging two 1024 tiles"){
    Model model{};
    Test_access access(model);
    access.set_position(3,3,1024);
    access.set_position(3,2,1024);
    access.move_down();
    CHECK(access.tile_at(3,3)== 2048);
    access.game_won();
    CHECK(model.game_won()==true);
    CHECK(model.game_over()==false);
}

TEST_CASE("easy loss by checkered board"){
    Model model{};
    Test_access access(model);
    CHECK(model.game_over()==false);
    access.set_position(0,0,4);
    access.set_position(1,1,4);
    access.set_position(2,2,4);
    access.set_position(3,3,4);

    access.set_position(0,2,4);
    access.set_position(1,3,4);
    access.set_position(2,0,4);
    access.set_position(3,1,4);

    access.set_position(0,1,8);
    access.set_position(0,3,8);
    access.set_position(1,0,8);
    access.set_position(1,2,8);

    access.set_position(2,1,8);
    access.set_position(2,3,8);
    access.set_position(3,0,8);
    access.set_position(3,2,8);
    access.move_right();
    access.game_lost();
    CHECK(model.game_over()==true);
}
TEST_CASE("move up"){
    Model model{};
    Test_access access(model);
    access.set_position(3,3,4);
    access.set_position(3,2,4);
    access.move_up();
    CHECK(access.tile_at(3,2) == 8);
    CHECK(access.tile_at(3,3) == 0);
}

TEST_CASE("move down"){
    Model model{};
    Test_access access(model);
    access.set_position(3,3,4);
    access.set_position(3,2,4);
    access.move_down();
    CHECK(access.tile_at(3,3) == 8);
}

TEST_CASE("move left"){
    Model model{};
    Test_access access(model);
    access.set_position(2,3,4);
    access.set_position(3,3,4);
    access.move_left();
    CHECK(access.tile_at(2,3) == 8);
    CHECK(access.tile_at(3,3) == 0);
}




TEST_CASE("move right"){
    Model model{};
    Test_access access(model);
    access.set_position(3,2,4);
    access.set_position(3,3,4);
    access.move_right();
    CHECK(access.tile_at(3,2) == 0);
    CHECK(access.tile_at(3,3) == 8);
}

TEST_CASE("high score"){
    Model model{};
    Test_access access(model);
    access.set_position(3,2,512);
    access.set_position(3,3,512);
    access.move_down();
    CHECK(access.high_score() == 1024);
}
Test_access::Test_access(Model& model)
        : model(model)
{ }
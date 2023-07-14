#include "model.hxx"
#include "model.hxx"
#include <iostream>

Model::Model()
        :
        made_move_(false),
        score_(0),
        game_over_(false),
        game_won_(false),
        game_started_(false)



{}

int Model::get_piece_at_position(int i, int j) const  {
    return board_[i][j];
}

int& Model::tile_at_position(int i,int j) {
    return board_[i][j];
}

void Model::get_highest_tile() {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j<4; j++ ){
            if(board_[i][j]> score_){
                score_ = board_[i][j];
            }
        }
    }

}
int Model::score() const
{
    return score_;
}
bool Model:: isGameStarted()  const{
    return game_started_;

}


bool Model::hasEmptySpace() const {
    for(int i = 0; i < 4; i++){
        for (int j =0; j< 4; j++){
            if (board_[i][j]==0){
                return true;
            }
        }

    }
    return false;
}
bool Model:: checkHorizontalGameOver() {
    for ( int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - 1; j++) {
            if (board_[i][j] == board_[i][j + 1]) {
                return false;
            }

        }
    }
    return true;
}


bool Model:: checkVerticalGameOver() {
    for ( int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - 1; j++) {
            if (board_[i][j] == board_[i+1][j]) {
                return false;
            }

        }
    }
    return true;
}
void Model::isGameOver() {
    if(hasEmptySpace()){
        game_over_= false;
    }
        // if it is full, it is dependent
    else {
        game_over_ =  checkHorizontalGameOver() && checkVerticalGameOver();}
}

void Model::isGameWon()  {
    for(int i = 0; i < 4; i++){
        for (int j =0; j< 4; j++){
            if(board_[i][j]>= 2048){
                game_won_ =  true;
            }
        }}

}

ge211::Posn<int> Model:: generate_unoccupied_position() const {
    int occupied = 1;
    int row;
    int col;
    while(occupied){
        row = rand() % 4;// pick a row 0-3
        col = rand() % 4; // and a column 0-3
        if(board_[row][col]==0){ // if this position on the board is unoccupied
            occupied = 0; // exit this while loop
        }
    }
    return {row,col}; // return this position
}

void Model:: addPiece() {
    ge211::Posn<int> position = generate_unoccupied_position(); // calls the
    // generate unoccupied position
    int v = std::rand() % 100; // generate a number 0-99
    int x;
    if(v>90){ // if the value is 90-99
        x = 4; // set the value to 4
    }
    else{
        x = 2; // otherwise generate a 2
    }
    board_[position.x][position.y] = x; // assign this value to the position
    // of the unoccupied position
}
void Model:: newGame()  {
    for(int i = 0; i < 4; i++){
        for (int j =0; j< 4; j++){
            board_[i][j] = 0; // generates an empty board
        }

    }
    addPiece(); // adds one piece to the board
    addPiece(); // adds another piece to the board
    game_started_ = true;
    game_over_ = false;
    score_ = 0;
    get_highest_tile();


}

// N is going to be a move up, E is going to be a move right, S is going
// to be a move down, W is going to be a move L
void Model:: advance_game(char cardinal_cord){
    if(cardinal_cord=='N'){
        //isGameOver();
        moveUp();
        get_highest_tile();
        if(made_move_){
            isGameWon();
            if(hasEmptySpace()){
                addPiece();
            }
        }
        isGameOver();
    }
    else if(cardinal_cord=='E'){
        //isGameOver();
        moveRight();
        get_highest_tile();
        if(made_move_){
            isGameWon();
            if(hasEmptySpace()){
                addPiece();
            }
        }
        isGameOver();

    }
    else if(cardinal_cord=='S'){
        //isGameOver();
        moveDown();
        get_highest_tile();
        if(made_move_){
            isGameWon();
            if(hasEmptySpace()){
                addPiece();
            }
        }
        isGameOver();

    }
    else if(cardinal_cord=='W'){
        //isGameOver();
        moveLeft();
        get_highest_tile();
        if(made_move_){
            isGameWon();
            if(hasEmptySpace()){
                addPiece();
            }
        }
        isGameOver();

    }

}




bool Model:: game_over() const{
    return game_over_;
}

bool Model:: game_won() const{
    return game_won_;
}

void Model:: moveUp() {
    made_move_ = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!board_[i][j]) { // if the current square is empty
                for (int k = j + 1; k < 4; k++) {
                    if (board_[i][k]) { // and a square below  it
                        // isn't
                        board_[i][j] = board_[i][k]; // move everything
                        // over to
                        // the right, as far as it can go
                        board_[i][k] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board_[i][j]!=0 && board_[i][j]==board_[i][j+1]) {
                board_[i][j] *= 2;
                board_[i][j + 1] = 0;
                made_move_ = true;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!board_[i][j]) { // if the current square is empty
                for (int k = j + 1; k < 4; k++) {
                    if (board_[i][k]) { // and a square below  it
                        // isn't
                        board_[i][j] = board_[i][k]; // move everything
                        // over to
                        // the right, as far as it can go
                        board_[i][k] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
}
void Model:: moveDown() {
    made_move_ = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0 ; j--) {
            if (board_[i][j]== 0) { // if the current square is empty
                for (int k = j - 1; k>=0; k--) {
                    if (board_[i][k]!= 0) { // and a square below  it
                        // isn't
                        board_[i][j] = board_[i][k]; // move everything
                        // over to
                        // the right, as far as it can go
                        board_[i][k] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j>= 1 ; j--) {
            if (board_[i][j]!=0 && board_[i][j]==board_[i][j-1]){
                board_[i][j] *= 2;
                board_[i][j-1] = 0;
                made_move_ = true;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0 ; j--) {
            if (board_[i][j]== 0) { // if the current square is empty
                for (int k = j - 1; k>=0; k--) {
                    if (board_[i][k]!= 0) { // and a square below  it
                        // isn't
                        board_[i][j] = board_[i][k]; // move everything
                        // over to
                        // the right, as far as it can go
                        board_[i][k] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
}
void Model:: moveRight()
{
    made_move_ = false;
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j<4 ; j++) {
            if (!board_[i][j]) { // if the current square is empty
                for (int k = i - 1; k >=0; k--) {
                    if (board_[k][j]) { // and a square to the right of it isn't
                        board_[i][j] = board_[k][j]; // move everything over to
                        // the right, as far as it can go
                        board_[k][j] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board_[i][j]!=0 && board_[i][j]==board_[i-1][j]){
                board_[i][j] *= 2;
                board_[i - 1][j] = 0;
                made_move_ = true;
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j<4 ; j++) {
            if (!board_[i][j]) { // if the current square is empty
                for (int k = i - 1; k >=0; k--) {
                    if (board_[k][j]) { // and a square to the right of it isn't
                        board_[i][j] = board_[k][j]; // move everything over to
                        // the right, as far as it can go
                        board_[k][j] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
}
void Model::moveLeft()
{
    made_move_ = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_[i][j] == 0) { // if the current square is empty
                for (int k = i + 1; k < 4; k++) {
                    if (board_[k][j]!= 0) { // and a square to the right of
                        // it isn't
                        board_[i][j] = board_[k][j]; // move everything
                        // over to
                        // the left, as far as it can go
                        board_[k][j] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_[i][j]!=0 && board_[i][j]==board_[i+1][j]){
                board_[i][j] *= 2;
                board_[i + 1][j] = 0;
                made_move_ = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_[i][j] == 0) { // if the current square is empty
                for (int k = i + 1; k < 4; k++) {
                    if (board_[k][j]!= 0) { // and a square to the right of
                        // it isn't
                        board_[i][j] = board_[k][j]; // move everything
                        // over to
                        // the left, as far as it can go
                        board_[k][j] = 0; // set the position where the tile
                        // was to be empty
                        made_move_ = true;
                        break;
                    }
                }
            }

        }
    }

}
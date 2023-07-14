#include "controller.hxx"

Controller::Controller()
        : model_(),
          view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}


View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_key(ge211::Key key){
    if(key == ge211::Key::code('q')){// if the q key is pressed, quit the game
        quit();
    }
    if (key == ge211::Key::code('r')){
        model_.newGame();
    }
    if(key == ge211::Key::right()){
        model_.advance_game('E');
    }
    if(key == ge211::Key::left()){
        model_.advance_game('W');
    }
    if(key == ge211::Key::up()){
        model_.advance_game('N');
    }
    if(key == ge211::Key::down()){
        model_.advance_game('S');
    }
}

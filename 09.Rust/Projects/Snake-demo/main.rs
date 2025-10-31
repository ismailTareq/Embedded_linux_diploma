mod draw;
mod snake;
mod game;
use piston_window::*;
use piston_window::types::Color;
use game::Game;
use draw::to_coord_u32;
const BACK_COLOR: Color = [0.5, 0.5, 0.5, 1.0];



fn main() {
    let (width, height) = (30, 30);

    let mut window: PistonWindow =
        WindowSettings::new("Snake", [to_coord_u32(width), to_coord_u32(height)])
            .exit_on_esc(true)
            .build()
            .unwrap();

    let mut game = Game::new(width, height);
    while let Some(event) = window.next() {
        if let Some(Button::Keyboard(key)) = event.press_args() {
            game.key_pressed(key);
        }
        window.draw_2d(&event, |c, g, _| {
            clear(BACK_COLOR, g);
            game.draw(&c, g);
        });

        event.update(|arg| {
            game.update_game(arg.dt);
        });
    }
}




// TESTING SNAKE.RS ONLY
// mod draw;
// mod snake; 
// mod game;
// use piston_window::*;
// use snake::{Direction, Snake};

// fn main() {
//     let mut window: PistonWindow =
//         WindowSettings::new("Snake skeleton", [300, 300])
//             .exit_on_esc(true).build().unwrap();

//     let mut snake = Snake::new(2, 3); // start column 2, row 3

//     while let Some(e) = window.next() {
//         if let Some(Button::Keyboard(Key::Space)) = e.press_args() {
//             snake.move_forward(None); // move right every space-bar
//         }

//         window.draw_2d(&e, |c, g, _| {
//             clear([0.1; 4], g);
//             snake.draw(&c, g); // draws 3 green blocks
//         });
//     }
// }


// TESTING DRAW.RS ONLY
// use piston_window::*; // pulls in everything above
// mod draw;    
// mod snake;        // the file we just analysed
// use draw::{draw_snake, draw_bordergame};
// use piston_window::types::Color;
// const BACKGROUND: Color = [0.1, 0.1, 0.2, 1.0];
// const SNAKE_GREEN: Color = [0.2, 0.8, 0.2, 1.0];
// const BORDER_GRAY: Color = [0.5, 0.5, 0.5, 1.0];

// fn main() {
//     let mut window: PistonWindow =
//         WindowSettings::new("Grid painter", [500, 400])
//             .exit_on_esc(true)
//             .resizable(false)
//             .build()
//             .unwrap();

//     while let Some(e) = window.next() {
//         window.draw_2d(&e, |c, g, _| {
//             // 1. clear
//             clear(BACKGROUND, g);

//             // 2. draw a 5×3 gray border (top-left at cell 2,2)
//             draw_bordergame(BORDER_GRAY, 2, 2, 5, 3, &c, g);

//             // 3. draw a single snake segment in the middle
//             draw_snake(SNAKE_GREEN, 4, 3, &c, g);
//         });
//     }
// }
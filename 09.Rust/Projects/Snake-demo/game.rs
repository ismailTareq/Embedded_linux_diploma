use piston_window::types::Color;
use piston_window::*;


use rand::{rng, Rng};

use crate::draw::{draw_snake, draw_bordergame, draw_food};
use crate::snake::{Direction, Snake};

const FOOD_COLOR: Color = [0.80, 0.00, 0.00, 1.0];
const BORDER_COLOR: Color = [0.00, 0.00, 0.00, 1.0];
const GAMEOVER_COLOR: Color = [0.90, 0.00, 0.00, 0.5];

const MOVING_PERIOD: f64 = 0.066;
const RESTART_TIME: f64 = 1.0;//1 sec

pub struct Game {
    snake: Snake,
    food_exists: bool,
    food_x: i32,
    food_y: i32,
    width: i32,
    height: i32,
    game_over: bool,
    waiting_time: f64,

}

impl Game {
    pub fn new(width: i32, height: i32) -> Game {
         Game {
            snake: Snake::new(2, 2),
            waiting_time: 0.0,
            food_exists: true,
            food_x: 6,
            food_y: 4,
            width,
            height,
            game_over: false,
        }
    }
    pub fn is_over(&self) -> bool { self.game_over }
    pub fn key_pressed(&mut self, key: Key) {
        if self.game_over {
            return;
        }

        let dir = match key {
            Key::Up => Some(Direction::Up),
            Key::Down => Some(Direction::Down),
            Key::Left => Some(Direction::Left),
            Key::Right => Some(Direction::Right),
            _ => Some(self.snake.head_direction()),
        };

        if let Some(dir) = dir {
            if dir == self.snake.head_direction().opposite() {
                return;
            }
        }

        self.update_snake(dir);
    }

    pub fn draw(&self, context: &Context, g: &mut G2d) {
        self.snake.draw(context, g);

        if self.food_exists {
            draw_food(FOOD_COLOR, self.food_x, self.food_y, context, g);
        }

        draw_bordergame(BORDER_COLOR, 0, 0, self.width, 1, context, g);//top
        draw_bordergame(BORDER_COLOR, 0, self.height - 1, self.width, 1, context, g);//botton
        draw_bordergame(BORDER_COLOR, 0, 0, 1, self.height, context, g);//left
        draw_bordergame(BORDER_COLOR, self.width - 1, 0, 1, self.height, context, g);//right

        if self.game_over {
            draw_bordergame(GAMEOVER_COLOR, 0, 0, self.width, self.height, context, g);//whole border
        }
    }

    pub fn update_game(&mut self, delta_time: f64) {
        self.waiting_time += delta_time;

        if self.game_over {
            if self.waiting_time > RESTART_TIME {
                self.restart();
            }
            return;
        }

        if !self.food_exists {
            self.add_food();
        }

        if self.waiting_time > MOVING_PERIOD {
            self.update_snake(None);
        }
    }

    fn check_eating(&mut self) {
        let (head_x, head_y): (i32, i32) = self.snake.head_position();
        if self.food_exists && self.food_x == head_x && self.food_y == head_y {
            self.food_exists = false;
            self.snake.snake_ate_food();
        }
    }

    fn check_if_snake_alive(&self, dir: Option<Direction>) -> bool {
        let (next_x, next_y) = self.snake.next_head(dir);

        if self.snake.overlap_food(next_x, next_y) {
            return false;//overlap the body
        }

        next_x > 0 && next_y > 0 && next_x < self.width - 1 && next_y < self.height - 1//border
    }

    fn add_food(&mut self) {
        let mut rng = rng();

        let mut new_x = rng.random_range(1..self.width - 1);
        let mut new_y = rng.random_range(1..self.height - 1);
        while self.snake.overlap_food(new_x, new_y) {
            new_x = rng.random_range(1..self.width - 1);
            new_y = rng.random_range(1..self.height - 1);
        }

        self.food_x = new_x;
        self.food_y = new_y;
        self.food_exists = true;
    }

    fn update_snake(&mut self, dir: Option<Direction>) {
        if self.check_if_snake_alive(dir) {
            self.snake.move_forward(dir);
            self.check_eating();
        } else {
            self.game_over = true;
        }
        self.waiting_time = 0.0;
    }

    fn restart(&mut self) {
        self.snake = Snake::new(2, 2);
        self.waiting_time = 0.0;
        self.food_exists = true;
        self.food_x = 6;
        self.food_y = 4;
        self.game_over = false;
    }
}
# Decorator

▶️[**Run**](https://godbolt.org/z/xjn3Warxo)

```rust
trait Coffee {
    fn get_cost(&self) -> i32;
    fn get_ingredients(&self) -> String;
}

struct SimpleCoffee;

impl Coffee for SimpleCoffee {
    fn get_cost(&self) -> i32 {
        10
    }

    fn get_ingredients(&self) -> String {
        String::from("coffee beans")
    }
}

struct MilkDecorator<T: Coffee> {
    coffee: T,
}

impl<T: Coffee> Coffee for MilkDecorator<T> {
    fn get_cost(&self) -> i32 {
        self.coffee.get_cost() + 1
    }

    fn get_ingredients(&self) -> String {
        format!("{}, milk", self.coffee.get_ingredients())
    }
}

fn main() {
    let coffee = SimpleCoffee;
    let milk_coffee = MilkDecorator { coffee: coffee };
    println!("Cost: {}", milk_coffee.get_cost());
    println!("Ingredients: {}", milk_coffee.get_ingredients());

    let coffee = SimpleCoffee;
    let milk_coffee = MilkDecorator { coffee: coffee };
    let double_milk_coffee = MilkDecorator {
        coffee: milk_coffee,
    };
    println!("Cost: {}", double_milk_coffee.get_cost());
    println!("Ingredients: {}", double_milk_coffee.get_ingredients());
}
```

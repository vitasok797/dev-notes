# Flexible argument types

```rust
enum Redirect {
    Url(Url),
    Post(Post),
    Action {
        action: String,
        id: u64,
    },
}

fn redirect_to(target: Redirect) {}

fn main() {
    redirect_to(Redirect::Url(url));
    
    redirect_to(Redirect::Post(post));
    
    redirect_to(Redirect::Action {
        action: "show".into(),
        id: 5,
    });
}
```

Additional `From` conversions:

```rust
impl From<Url> for Redirect {
    fn from(url: Url) -> Self {
        Self::Url(url)
    }
}

impl From<Post> for Redirect {
    fn from(post: Post) -> Self {
        Self::Post(post)
    }
}

fn redirect_to(target: impl Into<Redirect>) {
    let target = target.into();
    ...
}

redirect_to(url);
redirect_to(post);
redirect_to(Redirect::Action {...});
```

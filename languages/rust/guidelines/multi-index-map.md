# Multi-index map

```rust
use slab::Slab;
use std::collections::HashMap;
use std::hash::Hash;

struct SlotEntry<K1, K2, V> {
    key1: K1,
    key2: K2,
    value: V,
}

pub struct MultiIndexMap<K1, K2, V> {
    slab: Slab<SlotEntry<K1, K2, V>>,
    index1: HashMap<K1, usize>,
    index2: HashMap<K2, usize>,
}

impl<K1, K2, V> MultiIndexMap<K1, K2, V> {
    pub fn new() -> Self {
        Self {
            slab: Slab::new(),
            index1: HashMap::new(),
            index2: HashMap::new(),
        }
    }

    pub fn with_capacity(capacity: usize) -> Self {
        Self {
            slab: Slab::with_capacity(capacity),
            index1: HashMap::with_capacity(capacity),
            index2: HashMap::with_capacity(capacity),
        }
    }
}

impl<K1, K2, V> Default for MultiIndexMap<K1, K2, V> {
    fn default() -> Self {
        Self::new()
    }
}

impl<K1, K2, V> MultiIndexMap<K1, K2, V>
where
    K1: Eq + Hash + Clone,
    K2: Eq + Hash + Clone,
{
    pub fn insert(&mut self, k1: K1, k2: K2, value: V) -> Result<(), (K1, K2, V)> {
        if self.index1.contains_key(&k1) || self.index2.contains_key(&k2) {
            return Err((k1, k2, value));
        }

        let entry = SlotEntry {
            key1: k1.clone(),
            key2: k2.clone(),
            value,
        };

        let idx = self.slab.insert(entry);
        self.index1.insert(k1, idx);
        self.index2.insert(k2, idx);

        Ok(())
    }

    pub fn get_mut_by_k1(&mut self, k1: &K1) -> Option<&mut V> {
        let &idx = self.index1.get(k1)?;
        let entry = self.slab.get_mut(idx).unwrap();
        Some(&mut entry.value)
    }

    pub fn get_full_by_k1(&self, k1: &K1) -> Option<(&K1, &K2, &V)> {
        let &idx = self.index1.get(k1)?;
        let entry = self.slab.get(idx).unwrap();
        Some((&entry.key1, &entry.key2, &entry.value))
    }

    pub fn remove_by_k1(&mut self, k1: &K1) -> Option<V> {
        let idx = self.index1.remove(k1)?;
        let entry = self.slab.remove(idx);
        self.index2.remove(&entry.key2).unwrap();
        Some(entry.value)
    }
}
```

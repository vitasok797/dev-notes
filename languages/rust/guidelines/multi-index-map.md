# Multi-index map

```rust
use slab::Slab;
use std::collections::HashMap;

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

impl<K1, K2, V> MultiIndexMap<K1, K2, V>
where
    K1: Eq + std::hash::Hash + Clone,
    K2: Eq + std::hash::Hash + Clone,
{
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
        self.index2.remove(&entry.key2);
        Some(entry.value)
    }
}
```

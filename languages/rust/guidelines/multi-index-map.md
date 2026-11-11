# Multi-index map

```rust
use slab::Slab;
use std::borrow::Borrow;
use std::collections::HashMap;
use std::hash::Hash;

#[derive(Debug, Clone)]
struct SlotEntry<K1, K2, V> {
    key1: K1,
    key2: K2,
    value: V,
}

#[derive(Debug, Clone)]
pub struct BindexMap<K1, K2, V> {
    slab: Slab<SlotEntry<K1, K2, V>>,
    index1: HashMap<K1, usize>,
    index2: HashMap<K2, usize>,
}

impl<K1, K2, V> BindexMap<K1, K2, V> {
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

    pub fn len(&self) -> usize {
        self.slab.len()
    }

    pub fn is_empty(&self) -> bool {
        self.slab.is_empty()
    }

    pub fn clear(&mut self) {
        self.slab.clear();
        self.index1.clear();
        self.index2.clear();
    }

    pub fn iter(&self) -> impl Iterator<Item = (&K1, &K2, &V)> {
        self.slab
            .iter()
            .map(|(_, entry)| (&entry.key1, &entry.key2, &entry.value))
    }

    pub fn iter_mut(&mut self) -> impl Iterator<Item = (&K1, &K2, &mut V)> {
        self.slab
            .iter_mut()
            .map(|(_, entry)| (&entry.key1, &entry.key2, &mut entry.value))
    }

    fn find_entry<'a, K, Q>(
        slab: &'a Slab<SlotEntry<K1, K2, V>>,
        index: &HashMap<K, usize>,
        key: &Q,
    ) -> Option<&'a SlotEntry<K1, K2, V>>
    where
        K: Eq + Hash + Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        let &idx = index.get(key)?;
        Some(slab.get(idx).unwrap())
    }

    fn find_entry_mut<'a, K, Q>(
        slab: &'a mut Slab<SlotEntry<K1, K2, V>>,
        index: &HashMap<K, usize>,
        key: &Q,
    ) -> Option<&'a mut SlotEntry<K1, K2, V>>
    where
        K: Eq + Hash + Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        let &idx = index.get(key)?;
        Some(slab.get_mut(idx).unwrap())
    }
}

impl<K1, K2, V> Default for BindexMap<K1, K2, V> {
    fn default() -> Self {
        Self::new()
    }
}

impl<K1, K2, V> BindexMap<K1, K2, V>
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

    pub fn contains_k1<Q>(&self, k1: &Q) -> bool
    where
        K1: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        self.index1.contains_key(k1)
    }

    pub fn get_by_k1<Q>(&self, k1: &Q) -> Option<&V>
    where
        K1: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry(&self.slab, &self.index1, k1).map(|e| &e.value)
    }

    pub fn get_mut_by_k1<Q>(&mut self, k1: &Q) -> Option<&mut V>
    where
        K1: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry_mut(&mut self.slab, &self.index1, k1).map(|e| &mut e.value)
    }

    pub fn get_full_by_k1<Q>(&self, k1: &Q) -> Option<(&K1, &K2, &V)>
    where
        K1: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry(&self.slab, &self.index1, k1).map(|e| (&e.key1, &e.key2, &e.value))
    }

    pub fn remove_by_k1<Q>(&mut self, k1: &Q) -> Option<V>
    where
        K1: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        let idx = self.index1.remove(k1)?;
        let entry = self.slab.remove(idx);
        self.index2.remove(&entry.key2).unwrap();
        Some(entry.value)
    }

    pub fn contains_k2<Q>(&self, k2: &Q) -> bool
    where
        K2: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        self.index2.contains_key(k2)
    }

    pub fn get_by_k2<Q>(&self, k2: &Q) -> Option<&V>
    where
        K2: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry(&self.slab, &self.index2, k2).map(|e| &e.value)
    }

    pub fn get_mut_by_k2<Q>(&mut self, k2: &Q) -> Option<&mut V>
    where
        K2: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry_mut(&mut self.slab, &self.index2, k2).map(|e| &mut e.value)
    }

    pub fn get_full_by_k2<Q>(&self, k2: &Q) -> Option<(&K1, &K2, &V)>
    where
        K2: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        Self::find_entry(&self.slab, &self.index2, k2).map(|e| (&e.key1, &e.key2, &e.value))
    }

    pub fn remove_by_k2<Q>(&mut self, k2: &Q) -> Option<V>
    where
        K2: Borrow<Q>,
        Q: Eq + Hash + ?Sized,
    {
        let idx = self.index2.remove(k2)?;
        let entry = self.slab.remove(idx);
        self.index1.remove(&entry.key1).unwrap();
        Some(entry.value)
    }
}
```

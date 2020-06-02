package ADTs;

import Model.Values.Value;

import java.util.*;

public class MyDictionary<K, V> implements MyIDictionary<K, V> {

    private HashMap<K, V> dictionary;

    public MyDictionary(){
        this.dictionary = new HashMap<K, V>();
    }

    @Override
    public void put(K _key, V _value) {
        this.dictionary.put(_key, _value);
    }

    @Override
    public Collection<V> elements() {
        return this.dictionary.values();
    }

    @Override
    public V get(K _key) {
        return this.dictionary.get(_key);
    }

    @Override
    public boolean isEmpty() {
        return this.dictionary.isEmpty();
    }

    @Override
    public Collection<K> keys() {
        return this.dictionary.keySet();
    }

    @Override
    public V remove(K _key) {
        return this.dictionary.remove(_key);
    }

    @Override
    public int size() {
        return this.dictionary.size();
    }

    @Override
    public boolean contains(K _key) {
        return this.dictionary.containsKey(_key);
    }

    @Override
    public String toString()
    {
        String result = "";

        Iterator<K> it = (Iterator<K>) this.dictionary.keySet().iterator();

        while(it.hasNext()) {
            K key = it.next();
            V value = this.dictionary.get(key);
            result += key.toString() + " = " + value.toString() + "\n";
        }
        return result;
    }

    @Override
    public Object makeCopy() {
        HashMap<K, V> newDict = new HashMap<K, V>();

        Iterator<K> it = (Iterator<K>) this.dictionary.keySet().iterator();
        while(it.hasNext())
        {
            K key = it.next();
            V value = this.dictionary.get(key);
            newDict.put(key, (V) ((Value) value).makeCopy());
        }

        MyDictionary<K, V> result = new MyDictionary<K, V>();
        result.setEntrySet(newDict);

        return result;
    }

    public void setEntrySet(HashMap<K, V> newDict) {
        this.dictionary = newDict;
    }
}
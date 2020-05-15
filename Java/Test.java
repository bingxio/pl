package app.dao;

import java.util.LinkedList;

import app.entity.Item;

/***
 * Selector of dao layer of `Item`.
 * 
 * @param <T> Item entity.
 */
public class Selector<T> {
    LinkedList<T> linkedList = new LinkedList<T>();

    /**
     * It is used to find out item and the backup var.
     */
    int i = 0, x = 0;

    /***
     * Insert new entity of item into list.
     *
     * @param item
     */
    public void insert(T item) {
        linkedList.add(item);
    }

    /**
     * Replace new item into list.
     * 
     * @param id
     * @param name
     * @param desc
     * @param price
     * @return OK
     */
    public boolean modify(int id, String name, String desc, double price) {
        if (linkedList.isEmpty() || (Item) find(id) == null) {
            return false;
        }
        ((Item) linkedList.get(i)).setName(name);
        ((Item) linkedList.get(i)).setDesc(desc);
        ((Item) linkedList.get(i)).setPrice(price);
        return true;
    }

    /**
     * Delete item.
     * 
     * @param id
     * @return OK
     */
    public boolean delete(int id) {
        return linkedList.removeIf(x -> ((Item) x).getId() == id);
    }

    /**
     * Returned of boolean its found or not.
     * 
     * @param id
     * @return OK
     */
    public T find(int id) {
        //
        i = -1;
        //
        for (int k = 0; k < linkedList.size(); k ++) {
            Item item = (Item) linkedList.get(k);

            if (item.getId() == id) {
                i = k;
                break;
            }
        }
        //
        // linkedList.forEach(x -> {
        //     Item item = (Item) x;
        //     //
        //     if (item.getId() != id) {
        //         i = -1;
        //     } else {
        //         i = linkedList.
        //     }
        // });
        if (linkedList.isEmpty() || i == -1) {
            return null;
        }
        return linkedList.get(i);
    }
}

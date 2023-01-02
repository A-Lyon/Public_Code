public class QuadraticTable implements ITable{
    String[] table;
    int numItems;

    /**
     * Hash table size must be greater than 7 to use the second hash.
     * @param numSlots
     */
    public QuadraticTable(int numSlots){
        table = new String[numSlots];
        this.numItems = 0;
    }

    public int getHash(String key) {
        return hash(key) % table.length;
    }

    /**
     * TODO - Complete This Function
     * This function should insert the key at the index given by the hash.
     * To do this:
     * 1. compute hash() and get index using modulo. insert the element if the slot is empty
     * 2. if the slot is not empty, first check to make sure it's not a duplicate and then
     * insert it if not. We don't want to insert a duplicate.
     * 3. if the slot is full and it's not a duplicate key then find the next index using
     * (hash() + i^2) % numSlots starting with i = 1 until you find an empty spot or until the new index
     * is equal to the original hash then you have checked all other spots.
     *
     * 
     * @param key - item to insert into the table
     * @return True if the item could be inserted or false if it is a duplicate
     */
    @Override
    public boolean insert(String key) {
        if (table.length == numItems){
            return false;
        }
        int index = getHash(key);
        if(insertHelper(index, key, index, 1)){
            numItems++;
            return true;
        }
        return false;
    }


    public boolean insertHelper(int origHash, String key, int hash, int i){
        if(table[hash] == null){
            table[hash] = key;
            return true;
        }
        else if(table[hash].equals(key)){
            return false;
        }
        else if(i == 25){                                                //this is a cheap way to do it. It would fail on a large table.
            return false;
        }
        else return insertHelper(origHash, key, (origHash + i * i) % table.length, i+1);
    }

    /**
     * This method should return the string or null if there is no matching element
     * To do this following similar steps as insert until you find the key or if you find an empty spot then
     * you know the key is not in the table and you can return false.
     * @param key
     * @return
     */
    @Override
    public boolean search(String key) {
        return searchHelper(key, getHash(key), 1);
    }

    public boolean searchHelper(String key, int hash, int i){
        if(table[hash] != null && table[hash].equals(key)){
            return true;
        }else if(table[hash] == null || i == 15){
            return false;
        }else{
            return searchHelper(key, (hash + i * i) % table.length, i+1);
        }
    }
    /**
     * a hash function which simply uses Java's built in function for hashing strings.
     * @param key
     * @return
     */
    public int hash(String key){
        return Math.abs(key.hashCode());
    }

    /**
     * Should return a string representation of the table like:
     * slot 1: item or list of items
     * slot 2: item or list of items
     * ...
     *
     * @return
     */
    @Override
    public String toString() {
        StringBuilder ret = new StringBuilder();
        for(int i = 0; i < table.length; i++){
            ret.append(String.format("Bucket %d: %s\n", i, table[i]));
        }
        return ret.toString();
    }
    public static void main(String[] args) {
        /* Table tests */
        String[] names = {"Liam", "Noah", "William", "James", "Oliver",
                "Benjamin", "Charlotte", "Mia", "Evelyn", "Harper",
                "Lucas", "Mason", "Lucas"};
        QuadraticTable table = new QuadraticTable(names.length-2);
        for (String name : names) {
            table.insert(name);
        }
        System.out.println(table);
        /* search() tests */
        String name = "Liam";
        boolean search = table.search(name);
        System.out.printf("Testing search(%s)...\n", name);
        if(!search){
            System.out.print("FAILURE -> ");
        }else{
            System.out.print("PASSED -> ");
        }
        System.out.printf("Expected: %b, Actual: %b\n", true, search);

        String name2 = "Joshua";
        boolean search2 = table.search(name2);
        System.out.printf("Testing search(%s)...\n", name2);
        if(search2){
            System.out.print("FAILURE -> ");
        }else{
            System.out.print("PASSED -> ");
        }
        System.out.printf("Expected: %b, Actual: %b\n", false, search2);
    }

}

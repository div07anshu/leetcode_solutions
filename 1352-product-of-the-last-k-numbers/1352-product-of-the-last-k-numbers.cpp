class ProductOfNumbers {
public:
    int i = 0;
    vector<int> arr;
    ProductOfNumbers() { arr.resize(4 * 10000); }

    void add(int num) { arr[i++] = num; }

    int getProduct(int k) {
        int st = i - 1;
        int prod = 1;

        while (st > i - k - 1) {
            prod = prod * arr[st];
            st--;
        }

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
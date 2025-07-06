class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) :
        m_nums1(nums1), m_nums2(nums2), m_count() {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        // Setup pairs.
        m_count.reserve(10000);
        for (int j = 0; j < m_nums2.size(); j++) {
            insertValue(m_nums2[j]);
        }
    }
    
    void add(int index, int val) {
        removeValue(m_nums2[index]);
        m_nums2[index] += val;
        insertValue(m_nums2[index]);
    }
    
    int count(int tot) {
        int total = 0;
        for (int i = 0; i < m_nums1.size(); i++) {
            total += getCount(tot - m_nums1[i]);
        }
        return total;
    }

private:
    void removeValue(const int sum) {
        m_count[sum]--;
    }

    void insertValue(const int sum) {
        auto it = m_count.find(sum);
        if (it == m_count.end()) {
            m_count.emplace(sum, 1);
            return;
        }
        it->second++;
    }
    const int getCount(const int sum) const {
        auto it = m_count.find(sum);
        if (it == m_count.end())
            return 0;
        return it->second;
    }

private:
    std::vector<int> m_nums1, m_nums2;
    std::unordered_map<int, int> m_count;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
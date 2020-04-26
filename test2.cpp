class LRUNode{
public:
    int key;
    int value;
    LRUNode * prev;
    LRUNode * next;
};


class LRUCache {

public:
    unordered_map<int,LRUNode*> m_map;
    LRUNode * m_root;
    int m_capacity;
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_root = nullptr;
    }

    inline LRUNode * findNode(int key )
    {
        auto it = m_map.find(key);
        return (it != m_map.end())? it->second : nullptr;
    }

    inline void moveNodeToHead(LRUNode * node)
    {
        // if node is head exit (nothing to do)
        if ( node == m_root)
            return;

        // remove node from list. stitching up list
        // if there is a prev link then its an exiting node
        if ( node->prev )
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // connect node to head
        node->next = m_root;
        node->prev = m_root->prev;
        m_root->prev->next = node;
        m_root->prev = node;
        m_root = node;
    }

    int get(int key) {
        LRUNode * node = findNode(key);

        if (!node)
            return -1;

        moveNodeToHead(node);

        return m_root->value;
    }


    void put(int key, int value) {
        // find key
        LRUNode * node = findNode(key);

        // if key found move to front and change value
        if(node) {
            moveNodeToHead(node);
            node->value = value;
        } else {
            // check if at cap. if so use oldest node as
            // new node. remove from hash table
            // else create new node
            if( m_map.size() >= m_capacity)
            {
                m_map.erase(m_root->prev->key);

                node = m_root->prev;
                node->key = key;
                node->value = value;
           } else {
                node = new LRUNode;
                node->key = key;
                node->value = value;
                if ( !m_root )
                {
                    m_root = node;
                    m_root->next = m_root;
                    m_root->prev = m_root;
                } else {
                    node->next = m_root;
                    node->prev = m_root->prev;
                    node->prev->next = node;
                    m_root->prev = node;
                }

           }


            // add to hash map and set nodes value
            m_map[key] = node;
            m_root = node;
        }

        return;
    }

};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
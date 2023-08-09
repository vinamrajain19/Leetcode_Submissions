class Codec {
	public:
    
		string serialize(TreeNode *root) {
			string result = "";
			if (!root) {
				return result;
			}
            
            queue<TreeNode*> queue({ root });
			while (!queue.empty()) {
                // get the first node from the queue
				TreeNode *front = queue.front();
				queue.pop();
				if (front) {
                    // if the node exists, append val to result with delimiter
					result += to_string(front->val) + ",";
                    // push the left and right nodes into the queue without null check
					queue.push(front->left);
					queue.push(front->right);
				} else {
                    // if the node is null, append null indicator with delimiter
					result += "#,";
				}
			}
			return result;
		}

	TreeNode* deserialize(string data) {
		if (!data.size()) {
			return NULL;
		}
        // get first input from stream with delimiter and save to data
		stringstream stream(data);
		getline(stream, data, ',');
        // initialize tree root with string to integer conversion of data
		TreeNode *root = new TreeNode(stoi(data));
		queue<TreeNode*> queue({ root });
		while (!queue.empty()) {
            // get the first node from the queue
			TreeNode *front = queue.front();
			queue.pop();
            // get the next two inputs from stream as left and right
			string left, right;
			getline(stream, left, ',');
			getline(stream, right, ',');
			if (left == "#") {
                // if null indicator, set left node to null
				front->left = NULL;
			} else {
                // if not null, set left to new node and push to queue
				front->left = new TreeNode(stoi(left));
				queue.push(front->left);
			}
			if (right == "#") {
                // if null indicator, set right node to null
				front->right = NULL;
			} else {
                // if not null, set right to new node and push to queue
				front->right = new TreeNode(stoi(right));
				queue.push(front->right);
			}
		}
		return root;
	}
};
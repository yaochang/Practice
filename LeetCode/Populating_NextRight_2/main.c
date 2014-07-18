    void connect(TreeLinkNode *root) {
    	queue<TreeLinkNode*> odd;
	queue<TreeLinkNode*> even;
	TreeLinkNode *tmp;
	if(root==NULL) return;
	odd.push(root);
	while(!odd.empty() || !even.empty()){
		if(!odd.empty()){
			tmp = odd.front();
			odd.pop();
			if(tmp->left) even.push(tmp->left);
			if(tmp->right) even.push(tmp->right);
			while(!odd.empty()){
				tmp->next = odd.front();
				tmp = tmp->next;
				if(tmp->left) even.push(tmp->left);
				if(tmp->right) even.push(tmp->right);
				odd.pop();
			}
			tmp->next = NULL;
		}else{
			tmp = even.front();
			even.pop();
			if(tmp->left) odd.push(tmp->left);
			if(tmp->right) odd.push(tmp->right);
			while(!even.empty()){
				tmp->next = even.front();
				tmp = tmp->next;
				if(tmp->left) odd.push(tmp->left);
				if(tmp->right) odd.push(tmp->right);
				even.pop();
			}
			tmp->next = NULL;
		}
	}    
    }

class AVLNode{
	int key;
	AVLNode *left;
	AVLNode *right;
	int amount;

	int correct_height();
	int defect_height();
	int get_amount();
	AVLNode *rotate_left();
	AVLNode *rotate_right();
	AVLNode *correctm2();
	AVLNode *correct2();
	AVLNode *rebalance();
	public:
	AVLNode *insert(int);
	void print_all(int);
	int search_k_min(int);
	int amount_less_k(int);
	AVLNode(int);
};

static int trie::byte2int (byte character) const{
	return int(character);
}
int trie::get_val() const{
	return cur->val;
}

bool trie::exist_child(byte character) const{
	if (child[byte2int(character)]!=NULL){
		return true;
	}
	else {
		return false;
	}
}

void trie::add_new_node(byte character, code val){
	cur -> child[byte2int(character)] = new node(val);
}

void trie::go_to_child(byte character){
	cur = cur -> child[byte2int(character)];
}
void trie::reset(){
	cur = root;
}

node::node(){
	val = code(0);
	for (int i = 0;i<256;i++){
		child[i] = NULL;
	}
}

node::node(code set_val){
	val = set_val;
	for (int i = 0;i<256;i++){
		child[i] = NULL;
	}
}

node::~node(){
	for (int i=0;i<256;i++){
		if (child[i] != NULL){
			delete child[i];
		}
	}
}

trie::trie(){
	root = new node();
	cur = root;
}

trie::~trie(){
	delete root;
}

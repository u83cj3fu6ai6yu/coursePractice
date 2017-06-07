#include<iostream>
#include<cstring>
#include <map>
#include <queue>
#include<stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node {
	char s;
	int num;
	struct node *left, *right;
};
struct code {
	struct node *node;
	string s;
	int dir;
};
struct comp {
	bool operator()(struct node *n1, struct node *n2) {
		if(n1 == NULL || n2 == NULL)
			return true;
		else
			return n1->num>n2->num;
	}
};
struct len {
	char c;
	string s;
};
int cmp(const void *l1, const void *l2) {
	string s1(((struct len *)l1)->s);
	string s2(((struct len *)l2)->s);
	if (s1.length()>s2.length())
		return 1;
	if (s1.length()<s2.length())
		return -1;
	for (int i=0;i<s1.length();i++) {
		if (s1[i]!=s2[i]) {
			return s1[i]-s2[i];
		}
	}
	return 0;
}
int main() {
	map<char, int> m;
	char c;
	while ((c=getchar())>0) {
		if (c>=97 && c<=122) {
			if (m.find(c)==m.end()){
				m.insert(pair<char, int>(c,1));
			}
			else{
				m.find(c)->second++;
			}
		}
		else if (c=='\n')
			break;
	}
	priority_queue<struct node *, vector<struct node *>, comp> pq;
	for (map<char, int>::iterator iter=m.begin();iter!=m.end();iter++){
		struct node *n=new struct node;
		memset(n, 0, sizeof(struct node));
		n->s=iter->first;
		n->num=iter->second;
		pq.push(n);
	}
	while (true) {
		struct node *fa, *le, *ri;
		fa = new struct node;
		le = pq.top();
		pq.pop();
		ri = pq.top();
		pq.pop();
		fa->num = le->num + ri->num;
		fa->left = le;
		fa->right = ri;
		pq.push(fa);
		if (pq.size()==1)
			break;
	}
	struct node *n=pq.top();
	stack<struct code> st;
	struct code code;
	code.node=n;
	code.s="";
	code.dir=0;
	st.push(code);
	struct node *next, *o;
	string str, next_str;
	int dir;
	struct len *out=new struct len [26];
	int offset=0;
	while (st.size()) {
		code=st.top();
		st.pop();
		o=code.node;
		str=code.s;
		dir=code.dir;
		while (dir<2) {
			if (o->left==NULL && o->right==NULL) {
				//cout<<o->s<<":"<<str<<endl;
				out[offset].c=o->s;
				out[offset].s=str;
				offset++;
				break;
			}
			else {
				if (dir==0 && o->left!=NULL) {
					next=o->left;
					next_str=str+'0';
				}
				else if (o->right!=NULL){
					next=o->right;
					next_str=str+'1';
				}
				code.node=o;
				code.s=str;
				code.dir=++dir;
				st.push(code);
				o=next;
				str=next_str;
				dir=0;
			}
		}
	}
	qsort(out, offset, sizeof(struct len), cmp);
	for (int i=0;i<offset;i++)
		cout << out[i].c << ":" << out[i].s << endl;
}

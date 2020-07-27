#include <iostream>
#include <stack>

/* Classic Hanoi tower problem
   Using stacks to represent each tower
*/

using st = std::stack<int>;

struct augmentedStack {
	st stack;
	std::string name;
};

using as = augmentedStack;

void transferDisk(as& from, as& to) {
	to.stack.push(from.stack.top());
	std::cout << "Moving " << from.stack.top() << " from " << from.name << " to " << to.name <<"\n";
	from.stack.pop();
}

void arrange(as& from, as& aux, as& to, int numDiscs) {
	if (numDiscs == 1) {
		transferDisk(from, to);
		return;
	}
	arrange(from, to, aux, numDiscs - 1);
	transferDisk(from, to);
	arrange(aux, from, to, numDiscs - 1);
}

int main() {
	int numDiscs = 3;
	as initStack, midStack, endStack;
	initStack.name = "Source";
	midStack.name = "Auxilary";
	endStack.name = "Destination";
	for (int i=numDiscs-1; i >= 0; i--) {
		initStack.stack.push(i);
	}
	arrange(initStack, midStack, endStack, numDiscs);
	return 0;
}
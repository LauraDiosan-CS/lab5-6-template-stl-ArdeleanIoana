#include <iostream>
#include "tests.h"
#include "book.h"
#include "UI.h"
using namespace std;
int main()
{
	Test t;
	t.test_all();
	Repository repo("books.txt");
	Service service(repo);
	UI user_inter(service);
	user_inter.run();

	return 0;
}
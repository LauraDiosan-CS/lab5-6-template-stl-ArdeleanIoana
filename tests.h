#pragma once
#include <iostream>

#include "book.h"
#include <assert.h>
#include "repo.h"
#include "service.h"
class Test
{
public:
	void test_all();
	Test();
	
private:
	void test_domain();
	void test_repo();
	void test_service();
};
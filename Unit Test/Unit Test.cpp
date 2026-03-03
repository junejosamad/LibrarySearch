#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
// IMPORTANT: Make sure this path matches where your header file is located
#include "../SearchLibrary/SearchAlgorithms.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(SearchAlgorithmsTests)
	{
	public:
		SearchAlgorithms searchAlgo;

		// --- BINARY SEARCH TESTS ---
		TEST_METHOD(BinarySearch_EmptyArray_ReturnsMinusOne)
		{
			vector<int> arr = {};
			Assert::AreEqual(-1, searchAlgo.BinarySearch(5, arr));
		}

		TEST_METHOD(BinarySearch_FoundAtMiddle_ReturnsIndex)
		{
			vector<int> arr = { 10, 20, 30, 40, 50 };
			Assert::AreEqual(2, searchAlgo.BinarySearch(30, arr));
		}

		TEST_METHOD(BinarySearch_SearchUpperHalf_ReturnsIndex)
		{
			vector<int> arr = { 10, 20, 30, 40, 50 };
			Assert::AreEqual(4, searchAlgo.BinarySearch(50, arr));
		}

		TEST_METHOD(BinarySearch_SearchLowerHalf_ReturnsIndex)
		{
			vector<int> arr = { 10, 20, 30, 40, 50 };
			Assert::AreEqual(0, searchAlgo.BinarySearch(10, arr));
		}

		TEST_METHOD(BinarySearch_KeyNotFound_ReturnsMinusOne)
		{
			vector<int> arr = { 10, 20, 30, 40, 50 };
			Assert::AreEqual(-1, searchAlgo.BinarySearch(99, arr));
		}

		// --- LINEAR SEARCH TESTS ---
		TEST_METHOD(LinearSearch_EmptyArray_ReturnsMinusOne)
		{
			vector<int> arr = {};
			Assert::AreEqual(-1, searchAlgo.LinearSearch(5, arr));
		}

		TEST_METHOD(LinearSearch_FirstElement_ReturnsIndex)
		{
			vector<int> arr = { 5, 10, 15 };
			Assert::AreEqual(0, searchAlgo.LinearSearch(5, arr));
		}

		TEST_METHOD(LinearSearch_NotFound_ReturnsMinusOne)
		{
			vector<int> arr = { 5, 10, 15 };
			Assert::AreEqual(-1, searchAlgo.LinearSearch(99, arr));
		}

		// --- JUMP SEARCH TESTS ---
		TEST_METHOD(JumpSearch_EmptyArray_ReturnsMinusOne)
		{
			vector<int> arr = {};
			Assert::AreEqual(-1, searchAlgo.JumpSearch(5, arr));
		}

		TEST_METHOD(JumpSearch_KeyFound_ReturnsIndex)
		{
			vector<int> arr = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
			Assert::AreEqual(5, searchAlgo.JumpSearch(5, arr));
		}

		TEST_METHOD(JumpSearch_KeyLargerThanAll_ReturnsMinusOne)
		{
			vector<int> arr = { 0, 1, 1, 2, 3, 5, 8 };
			Assert::AreEqual(-1, searchAlgo.JumpSearch(99, arr));
		}

		TEST_METHOD(JumpSearch_KeyLargerThanAll_ReturnsMinusOne)
		{
			vector<int> arr = { 0, 1, 1, 2, 3, 5, 8, 10 };
			Assert::AreEqual(-1, searchAlgo.JumpSearch(99, arr));
		}


		TEST_METHOD(JumpSearch_KeyLargerThanAll_ReturnsMinusOne)
		{
			vector<int> arr = { 0, 1, 1, 2, 3, 5, 8, 10, 11 };
			Assert::AreEqual(-1, searchAlgo.JumpSearch(99, arr));
		}
	};
}

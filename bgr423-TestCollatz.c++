// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("75 110011\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(    75, i);
    ASSERT_EQ(110011, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("300978 302354\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(300978, i);
    ASSERT_EQ(302354, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("801 801\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(801, i);
    ASSERT_EQ(801, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(115, 112115);
    ASSERT_EQ(354, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(969699, 970888);
    ASSERT_EQ(458, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(477777, 467676);
    ASSERT_EQ(413, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(139, 205);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(997884, 997884);
    ASSERT_EQ(228, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 616, 116, 144);
    ASSERT_EQ("616 116 144\n", w.str());}
TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 725123, 723999, 362);
    ASSERT_EQ("725123 723999 362\n", w.str());}
TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 9999, 990, 262);
    ASSERT_EQ("9999 990 262\n", w.str());}


// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("9335 6335\n2 2004\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("9335 6335 260\n2 2004 182\n", w.str());}
TEST(CollatzFixture, solve_2) {
    istringstream r("725300 724000\n723935 720935\n115935 131313\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("725300 724000 362\n723935 720935 411\n115935 131313 344\n", w.str());}
TEST(CollatzFixture, solve_3) {
    istringstream r("997600 997400\n862268 863368\n770001 773691\n648789 649119\n591804 601805\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("997600 997400 321\n862268 863368 326\n770001 773691 393\n648789 649119 385\n591804 601805 403\n", w.str());}

#include "pch.h"
#include <sstream>

TEST(TestAnswer, TestOneTry) {
	stringstream ss, out;
	ss.str("3");
	EXPECT_EQ(answer(ss, out, 1, 5), 3);
	ss.clear();
	ss.str("-10");
	EXPECT_EQ(answer(ss, out, -10, 10), -10);
	ss.clear();
	ss.str("6");
	EXPECT_EQ(answer(ss, out, 0, 6), 6);
}

TEST(TestAnswer, TestSomeTries) {
	stringstream ss, out;
	ss.str("6\n2");
	EXPECT_EQ(answer(ss, out, 1, 5), 2);
	ss.clear();
	ss.str("7\n8\n3");
	EXPECT_EQ(answer(ss, out, 1, 3), 3);
	ss.clear();
	ss.str("6\n6\n6\n6\n5");
	EXPECT_EQ(answer(ss, out, 5, 5), 5);
}

TEST(TestAnswer, TestTriesWithIgnore) {
	stringstream ss, out;
	ss.str("dog\n2");
	EXPECT_EQ(answer(ss, out, 1, 5), 2);
	ss.clear();
	ss.str("cat\n8\ndog\n3");
	EXPECT_EQ(answer(ss, out, 3, 5), 3);
	ss.clear();
	ss.str("cat\ncat\ncat\ndog\n5\ncat     dog\n6");
	EXPECT_EQ(answer(ss, out, 6, 10), 6);
}

TEST(TestAnswerDouble, TestOneTry) {
	stringstream ss, out;
	ss.str("3.5");
	ASSERT_NEAR(answer_double(ss, out, 1, 5), 3.5, 1e-9);
	ss.clear();
	ss.str("-10.33");
	ASSERT_NEAR(answer_double(ss, out, -10.34, 10), -10.33, 1e-9);
	ss.clear();
	ss.str("6");
	ASSERT_NEAR(answer_double(ss, out, 0, 6), 6, 1e-9);
}

TEST(TestAnswerDouble, TestSomeTries) {
	stringstream ss, out;
	ss.str("6.5\n2.3");
	ASSERT_NEAR(answer_double(ss, out, 1.2, 5.8), 2.3, 1e-9);
	ss.clear();
	ss.str("7.7\n8.8\n3.3");
	ASSERT_NEAR(answer_double(ss, out, 1, 3.3), 3.3, 1e-9);
	ss.clear();
	ss.str("6\n6.3\n6.2\n6.1\n5");
	ASSERT_NEAR(answer_double(ss, out, 5, 5), 5, 1e-9);
}

TEST(TestAnswerDouble, TestTriesWithIgnore) {
	stringstream ss, out;
	ss.str("dog\n2.4");
	ASSERT_NEAR(answer_double(ss, out, 1, 5), 2.4, 1e-9);
	ss.clear();
	ss.str("cat\n8.1\ndog\n3.0");
	ASSERT_NEAR(answer_double(ss, out, 3, 5), 3, 1e-9);
	ss.clear();
	ss.str("cat\ncat\ncat\ndog\n5\ncat     dog\n6.6");
	ASSERT_NEAR(answer_double(ss, out, 6, 10), 6.6, 1e-9);
}

TEST(TestDeltoida, TestConstructor) {
	ASSERT_NO_THROW(Deltoida(1));
	ASSERT_EQ(Deltoida(3).r(), 3);
	ASSERT_EQ(Deltoida(3).R(), 9);
	ASSERT_EQ(Deltoida(1).R(), 3);
	ASSERT_EQ(Deltoida(5).R(), 15);
}

TEST(TestDeltoida, TestSetter) {
	Deltoida d(1);
	ASSERT_TRUE(d.set_r(3));
	ASSERT_EQ(d.r(), 3);
	ASSERT_EQ(d.R(), 9);

	ASSERT_FALSE(d.set_r(-1));
	ASSERT_EQ(d.r(), 3);
	ASSERT_EQ(d.R(), 9);

	ASSERT_FALSE(d.set_r(0));
	ASSERT_EQ(d.r(), 3);
	ASSERT_EQ(d.R(), 9);
}

TEST(TestDeltoida, TestIntersection) {
	ASSERT_NEAR(Deltoida(1).intersection_length(), 4, 1e-9);
	ASSERT_NEAR(Deltoida(11.5).intersection_length(), 46, 1e-9);
	ASSERT_NEAR(Deltoida(18.3).intersection_length(), 73.2, 1e-9);
}

TEST(TestDeltoida, TestLength) {
	ASSERT_NEAR(Deltoida(1).length(), 16, 1e-9);
	ASSERT_NEAR(Deltoida(11.5).length(), 184, 1e-9);
	ASSERT_NEAR(Deltoida(18.3).length(), 292.8, 1e-9);
}

TEST(TestDeltoida, TestArea) {
	ASSERT_NEAR(Deltoida(1).S(), 6.28318, 1e-9);
	ASSERT_NEAR(Deltoida(11.5).S(), 830.950555, 1e-9);
	ASSERT_NEAR(Deltoida(18.3).S(), 2104.1741502, 1e-9);
}

TEST(TestDeltoida, TestGetX) {
	ASSERT_NEAR(Deltoida(1).x(1.5), -0.84851809326, 1e-9);
	ASSERT_NEAR(Deltoida(1).x(1.66), -1.16229841085, 1e-9);

	ASSERT_NEAR(Deltoida(11.5).x(0.03), 34.4689569854, 1e-9);
	ASSERT_NEAR(Deltoida(11.5).x(0.12), 34.0049853354, 1e-9);

	ASSERT_NEAR(Deltoida(18.3).x(0), 54.9, 1e-9);
	ASSERT_NEAR(Deltoida(18.3).x(0.55), 39.503206529465, 1e-9);
}

TEST(TestDeltoida, TestGetY) {
	ASSERT_NEAR(Deltoida(1).y(1.5), 2.13610998127, 1e-9);
	ASSERT_NEAR(Deltoida(1).y(1.66), 1.814585555, 1e-9);

	ASSERT_NEAR(Deltoida(11.5).y(0.03), 1.3794825791, 1e-9);
	ASSERT_NEAR(Deltoida(11.5).y(0.12), 5.4869609715, 1e-9);

	ASSERT_NEAR(Deltoida(18.3).y(0), 0, 1e-9);
	ASSERT_NEAR(Deltoida(18.3).y(0.55), 35.439447267, 1e-9);
}

TEST(TestDeltoida, TestEquation) {
	ASSERT_STREQ(Deltoida(1).equation().c_str(), "(x^2 + y^2)^2 + 18.00*(x^2 + y^2) - 27.00 = 8.00*(x^3 - 3*x*y^2)");
	ASSERT_STREQ(Deltoida(22.5).equation().c_str(), "(x^2 + y^2)^2 + 9112.50*(x^2 + y^2) - 6919804.69 = 180.00*(x^3 - 3*x*y^2)");
	ASSERT_STREQ(Deltoida(5.1).equation().c_str(), "(x^2 + y^2)^2 + 468.18*(x^2 + y^2) - 18266.04 = 40.80*(x^3 - 3*x*y^2)");
}

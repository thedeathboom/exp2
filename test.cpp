#include "pch.h"
#include "../AllInOne/AllInOne.h"

// 构建的节点数目和属性是否正确
TEST(Test, T_01)
{
	// 手动构建一棵树，只有一个节点
	struct _Expr *exp;
	BuildTree(exp, 1);
	// 考虑只有一个节点的情况
	EXPECT_EQ(exp->expLeft, nullptr);
	EXPECT_EQ(exp->expRight, nullptr);
	EXPECT_EQ(exp->op, nullptr);
	EXPECT_EQ(exp->vt, VT_BAD);
	DestroyTree(exp);		// 别忘了销毁
}
// 构建的节点数目和属性是否正确
TEST(Test, T_02)
{
	// 手动构建一棵树，一共两个叶节点
	struct _Expr *exp, *L, *R;
	BuildTree(exp, 2);
	L = exp->expLeft;
	R = exp->expRight;
	// 应该左右各生成一个
	EXPECT_NE(L, nullptr);
	EXPECT_NE(R, nullptr);

	EXPECT_EQ(exp->op, nullptr);
	EXPECT_EQ(exp->vt, VT_BAD);
	DestroyTree(exp);
}
// 统计树中的叶节点个数
int TEST_LeafNumber(struct _Expr *exp)
{
	if (!exp->expLeft && !exp->expRight)
		return 1;
	return TEST_LeafNumber(exp->expRight) + TEST_LeafNumber(exp->expLeft);;
}
// 构建的节点数目是否正确
TEST(Test, T_03)
{
	// 手动构建一棵树，一百个叶节点
	struct _Expr *exp;
	int n;
	BuildTree(exp, 100);
	n = TEST_LeafNumber(exp);
	EXPECT_EQ(n, 100);
	DestroyTree(exp);
}
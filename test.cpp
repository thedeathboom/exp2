#include "pch.h"
#include "../AllInOne/AllInOne.h"

// �����Ľڵ���Ŀ�������Ƿ���ȷ
TEST(Test, T_01)
{
	// �ֶ�����һ������ֻ��һ���ڵ�
	struct _Expr *exp;
	BuildTree(exp, 1);
	// ����ֻ��һ���ڵ�����
	EXPECT_EQ(exp->expLeft, nullptr);
	EXPECT_EQ(exp->expRight, nullptr);
	EXPECT_EQ(exp->op, nullptr);
	EXPECT_EQ(exp->vt, VT_BAD);
	DestroyTree(exp);		// ����������
}
// �����Ľڵ���Ŀ�������Ƿ���ȷ
TEST(Test, T_02)
{
	// �ֶ�����һ������һ������Ҷ�ڵ�
	struct _Expr *exp, *L, *R;
	BuildTree(exp, 2);
	L = exp->expLeft;
	R = exp->expRight;
	// Ӧ�����Ҹ�����һ��
	EXPECT_NE(L, nullptr);
	EXPECT_NE(R, nullptr);

	EXPECT_EQ(exp->op, nullptr);
	EXPECT_EQ(exp->vt, VT_BAD);
	DestroyTree(exp);
}
// ͳ�����е�Ҷ�ڵ����
int TEST_LeafNumber(struct _Expr *exp)
{
	if (!exp->expLeft && !exp->expRight)
		return 1;
	return TEST_LeafNumber(exp->expRight) + TEST_LeafNumber(exp->expLeft);;
}
// �����Ľڵ���Ŀ�Ƿ���ȷ
TEST(Test, T_03)
{
	// �ֶ�����һ������һ�ٸ�Ҷ�ڵ�
	struct _Expr *exp;
	int n;
	BuildTree(exp, 100);
	n = TEST_LeafNumber(exp);
	EXPECT_EQ(n, 100);
	DestroyTree(exp);
}
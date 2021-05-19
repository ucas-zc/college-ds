#include "dlist.h"
#include "gtest/gtest.h"

namespace 
{
    class TestDList : public testing::Test
    {
        void SetUp() override
        {};

        void TearDown() override
        {};
    };
}

TEST_F(TestDList, TEST_DLIST)
{
    ds::dlist<int32_t> m_dlist;

    // 测试头结点后面插入新结点
    ds::dlist<int32_t> *pNode = new ds::dlist<int32_t>;
    pNode->m_dlist_data = 1;
    ASSERT_EQ(DS_OK, m_dlist.head_add(pNode));
    ASSERT_EQ(1, m_dlist.size());

    // 测试头结点后面插入新结点
    pNode = new ds::dlist<int32_t>;
    pNode->m_dlist_data = 2;
    ASSERT_EQ(DS_OK, m_dlist.tail_add(pNode));
    ASSERT_EQ(2, m_dlist.size());

    // 测试当前结点后面插入新结点
    ds::dlist<int32_t> *pNewNode = new ds::dlist<int32_t>;
    pNewNode->m_dlist_data = 4;
    ASSERT_EQ(DS_OK, m_dlist.next_add(pNode, pNewNode));
    ASSERT_EQ(3, m_dlist.size());

    // 测试当前结点前面插入新结点
    ds::dlist<int32_t> *pTemp = new ds::dlist<int32_t>;
    pTemp->m_dlist_data = 3;
    ASSERT_EQ(DS_OK, m_dlist.prev_add(pNewNode, pTemp));
    ASSERT_EQ(4, m_dlist.size());
   
    // 测试后向遍历
    pTemp = nullptr;
    int32_t temp = 1;
    while (DS_OK == m_dlist.forward_traver(pTemp))
    {
         ASSERT_EQ(temp++, pTemp->m_dlist_data);
    }

    // 测试前向遍历
    pTemp = nullptr;
    temp = 4;
    while (DS_OK == m_dlist.backward_traver(pTemp))
    {
         ASSERT_EQ(temp--, pTemp->m_dlist_data);
    } 

    // 测试销毁链表
    ASSERT_EQ(DS_OK, m_dlist.destroy());
    ASSERT_EQ(0, m_dlist.size());
}

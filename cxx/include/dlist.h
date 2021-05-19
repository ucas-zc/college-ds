#ifndef _DLIST_H_
#define _DLIST_H_

#include <iostream>
#include <cstdint>
#include "ds.h"

namespace ds
{
    template <typename _type>
    class dlist
    {
        public:
            /**
             * @brief 构造函数
             */
            dlist() : _dlist_prev(this), _dlist_next(this), _dlist_len(0)
            {}

            /**
             * @brief 析构函数
             */
            ~dlist()
            {}

            /**
             * @brief 当前结点开始前向添加结点
             *
             * @prame pCurNode 当前结点；pNewNode 新插入结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t prev_add(dlist<_type> *pCurNode, dlist<_type> *pNewNode)
            {
                // 如果链长小于0或者结点为nullptr则返回失败
                if (0 > _dlist_len || !pCurNode || !pNewNode)
                    return DS_FAIL;

                // 结点插入操作
                pCurNode->_dlist_prev->_dlist_next = pNewNode;
                pNewNode->_dlist_prev = pCurNode->_dlist_prev;
                pCurNode->_dlist_prev = pNewNode;
                pNewNode->_dlist_next = pCurNode;

                // 统计链表长度
                ++_dlist_len;
                return DS_OK;
            }

            
            /**
             * @brief 当前结点开始后向添加结点
             *
             * @prame pCurNode 当前结点；pNewNode 新插入结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t next_add(dlist<_type> *pCurNode, dlist<_type> *pNewNode)
            {
                // 如果链长小于0或者结点为nullptr则返回失败
                if (0 > _dlist_len || !pCurNode || !pNewNode)
                    return DS_FAIL;

                // 结点插入操作
                pCurNode->_dlist_next->_dlist_prev = pNewNode;
                pNewNode->_dlist_next = pCurNode->_dlist_next;
                pCurNode->_dlist_next = pNewNode;
                pNewNode->_dlist_prev = pCurNode;
            
                // 统计链表长度
                ++_dlist_len;
                return DS_OK;
            }

            /**
             * @brief 头节点后添加结点
             *
             * @prame pNewNode 新插入结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t head_add(dlist<_type> *pNewNode)
            {
                // 如果链长小于0或者结点为nullptr则返回失败
                if (0 > _dlist_len || !pNewNode)
                    return DS_FAIL;

                // 新结点插入
                if (DS_OK != next_add(this, pNewNode))
                    return DS_FAIL;
                return DS_OK;
            }

            /**
             * @brief 尾节点后添加结点
             *
             * @prame pNewNode 新插入结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t tail_add(dlist<_type> *pNewNode)
            {
                // 如果链长小于0或者结点为nullptr则返回失败
                if (0 > _dlist_len || !pNewNode)
                    return DS_FAIL;

                // 新结点插入
                if (DS_OK != prev_add(this, pNewNode))
                    return DS_FAIL;
                return DS_OK;
            }

            /**
             * @brief 由当前结点向后遍历一个结点
             *
             * @prame pCurNode 当前结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t forward_traver(dlist<_type> *&pCurNode)
            {
                // 当前结点空，则返回头节点后面的结点
                // 当前结点非空，则返回当前结点后面的结点
                if (!pCurNode)
                    pCurNode = this->_dlist_next;
                else
                    pCurNode = pCurNode->_dlist_next;
 
                return pCurNode != this ? DS_OK : DS_FAIL;
            }
            
            /**
             * @brief 由当前结点向前遍历一个结点
             *
             * @prame pCurNode 当前结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t backward_traver(dlist<_type> *&pCurNode)
            {
                // 当前结点空，则返回头节点后面的结点
                // 当前结点非空，则返回当前结点后面的结点
                if (!pCurNode)
                    pCurNode = this->_dlist_prev;
                else
                    pCurNode = pCurNode->_dlist_prev;
 
                return pCurNode != this ? DS_OK : DS_FAIL;
            }

            /**
             * @brief 弹出一个结点
             *
             * @prame pCurNode 需弹出结点
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t pop(dlist<_type> *pCurNode)
            {
                // 如果链长小于0或者结点为nullptr则返回失败
                if (0 > _dlist_len || !pCurNode)
                    return DS_FAIL;

                // 弹出结点操作
                pCurNode->_dlist_prev->_dlist_next = pCurNode->_dlist_next;
                pCurNode->_dlist_next->_dlist_prev = pCurNode->_dlist_prev;
                pCurNode->_dlist_prev = pCurNode;
                pCurNode->_dlist_next = pCurNode;

                // 链表长度-1
                --_dlist_len;
                return DS_OK;
            }

            /**
             * @brief 销毁链表
             *
             * @return DS_OK 成功；DS_FAIL 失败
             */
            int32_t destroy()
            {
                // 遍历所有结点
                dlist<_type> *pNode = nullptr;
                while (DS_OK == forward_traver(pNode))
                {
                    // 弹出结点
                    if (!pNode || DS_OK != pop(pNode))
                        return DS_FAIL;

                    // 将弹出结点内存释放
                    if (pNode) {
                        delete pNode;
                        pNode = nullptr;
                    }
                }
                 
                return DS_OK;
            }
            
            /**
             * @brief 获取链表长度
             *
             * @return 链表长度
             */
            int32_t size()
            {
                return _dlist_len;
            }

        public:
            /**
             * @brief 数据域
             */
            _type m_dlist_data;

        private:
            /**
             * @brief 前向指针
             */
            ds::dlist<_type> *_dlist_prev;


            /**
             * @brief 后向指针
             */
            ds::dlist<_type> *_dlist_next;

            /**
             * @brief 双向链表长度
             */
            int32_t _dlist_len;
    };
}

#endif

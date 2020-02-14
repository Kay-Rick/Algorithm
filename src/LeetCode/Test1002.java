/**
 * @Author: Rick
 * @Date: 2019/12/7 20:02
 * @Description:
 */
public class Test1002 {

    /**
     * 注意空指针异常的情况
     * @param l1
     * @param l2
     * @return
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        //初始化一个结点
        ListNode node = new ListNode(0);
        ListNode result = node;

        while (l1 != null && l2 != null){
            //  没有进位的情况
            if (node.val + l1.val + l2.val < 10){
                node.val += l1.val + l2.val;
                //  这里必须进行判断,否则可能会多出一个0节点
                if (l1.next != null || l2.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            //  针对存在进位的情况,这里放心地创建新的节点
            else{
                node.val += l1.val + l2.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }
            //  循环
            l1 = l1.next;
            l2 = l2.next;
        }

        //  针对l1还有值的情况
        while (l1 != null){
            if (node.val + l1.val >= 10){
                node.val = l1.val + node.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }else {
                node.val = l1.val + node.val;
                if (l1.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            l1 = l1.next;
        }

        //针对l2还有值
        while (l2 != null){
            if (node.val + l2.val >= 10){
                node.val = l2.val + node.val - 10;
                node.next = new ListNode(1);
                node = node.next;
            }else {
                node.val = l2.val + node.val;
                if (l2.next != null){
                    node.next = new ListNode(0);
                    node = node.next;
                }
            }
            l2 = l2.next;
        }
        return result;
    }
}


class ListNode{
    int val;
    ListNode next;
    ListNode(int x){
        val = x;
    }
}


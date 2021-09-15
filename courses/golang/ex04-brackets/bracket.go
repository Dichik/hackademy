package brackets

type Stack struct {
	items []int
}

func New() *Stack {
	var stack = Stack{nil}
	return &stack
}

func (stack *Stack) Push(element int) {
	if stack.items == nil {
		stack.items = []int{}
	}
	stack.items = append(stack.items, element)
}

func (stack *Stack) Pop() int {
	x := stack.items[len(stack.items) - 1]
	stack.items = stack.items[0:len(stack.items) - 1]
	return x
}

func (stack *Stack) Size() int {
	return len(stack.items)
}

func Bracket(str string) (bool, error) {
	mp := make(map[string]int)
	mp["("] = 1
	mp[")"] = -1
	mp["{"] = 2
	mp["}"] = -2
	mp["["] = 3
	mp["]"] = -3
	var stack = *New()
	for i := 0; i < len(str); i++ {
		x := mp[string(str[i])]
		if x > 0 {
			stack.Push(x)
		} else {
			if stack.Size() == 0 {
				return false, nil
			}
			res := x + stack.Pop()
			if res != 0 {
				return false, nil
			}
		}
	}
	return stack.Size() == 0, nil
}

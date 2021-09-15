package stack

type Stack struct {
	items []int
}

func New() *Stack {
	var stack Stack = Stack{nil}
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
class Todo {
    constructor() {
        this.tasks = [];
    }
    addTask(task) {
        this.tasks.push(task);
    }
    removeTask(task) {
        let index = this.tasks.indexOf(task);
        if (index !== -1) {
            this.tasks.splice(index, 1);
        }
    }
    getTasks() {
        return this.tasks;
    }
}

let myTodo = new Todo();

myTodo.addTask("Make a script in C++");
myTodo.addTask("Make a script in Lua");
myTodo.addTask("Make a script in JavaScript");
myTodo.addTask("Make a script in Python");
myTodo.addTask("Make a script in C#")

console.log(myTodo.getTasks());

myTodo.removeTask("Make a script in C++");
myTodo.removeTask("Make a script in Lua")

console.log(myTodo.getTasks());

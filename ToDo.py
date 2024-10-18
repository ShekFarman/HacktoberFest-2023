# Simple To-Do List Application

# Initialize an empty list to store tasks
todo_list = []

def show_menu():
    print("\n===== TO-DO LIST MENU =====")
    print("1. View To-Do List")
    print("2. Add Task")
    print("3. Mark Task as Completed")
    print("4. Delete Task")
    print("5. Exit")

def view_tasks():
    if len(todo_list) == 0:
        print("Your to-do list is empty.")
    else:
        print("\nYour To-Do List:")
        for idx, task in enumerate(todo_list, start=1):
            status = "✓" if task["completed"] else "✗"
            print(f"{idx}. [{status}] {task['task']}")

def add_task():
    task = input("Enter a new task: ")
    todo_list.append({"task": task, "completed": False})
    print(f"Task '{task}' has been added.")

def mark_completed():
    if len(todo_list) == 0:
        print("Your to-do list is empty.")
    else:
        view_tasks()
        task_num = int(input("Enter the task number to mark as completed: "))
        if 1 <= task_num <= len(todo_list):
            todo_list[task_num - 1]["completed"] = True
            print(f"Task '{todo_list[task_num - 1]['task']}' has been marked as completed.")
        else:
            print("Invalid task number.")

def delete_task():
    if len(todo_list) == 0:
        print("Your to-do list is empty.")
    else:
        view_tasks()
        task_num = int(input("Enter the task number to delete: "))
        if 1 <= task_num <= len(todo_list):
            removed_task = todo_list.pop(task_num - 1)
            print(f"Task '{removed_task['task']}' has been deleted.")
        else:
            print("Invalid task number.")

def main():
    while True:
        show_menu()
        choice = input("Enter your choice (1-5): ")

        if choice == "1":
            view_tasks()
        elif choice == "2":
            add_task()
        elif choice == "3":
            mark_completed()
        elif choice == "4":
            delete_task()
        elif choice == "5":
            print("Exiting the To-Do List application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

# Run the application
if __name__ == "__main__":
    main()

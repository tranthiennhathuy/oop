class Book {
    constructor(
        protected id: number,
        protected title: string,
        protected author: string,
        protected year: number,
        protected available: boolean
    ) { }

    public borrowBook(): void {
        if (this.available == true) this.available = false;
        else console.log(`Không cho mượn!`);
    }

    public returnBook(): void {
        this.available = true;
    }

    public getAvailable(): boolean {
        return this.available;
    }

    public getTitle(): string {
        return this.title;
    }
};

class Member {
    constructor(
        protected id: number,
        protected name: string,
        protected borrowedBooks: Book[] = []
    ) { }

    public borrow(book: Book): void {
        if (this.borrowedBooks.length < 5 && book.getAvailable() == true) {
            this.borrowedBooks.push(book);
            book.borrowBook();
            console.log(`${this.name} đã mượn: ${book.getTitle()}`);
        } else {
            console.log(`${this.name} không thể mượn: ${book.getTitle()}`);
        }
    }

    public return(book: Book): void {
        this.borrowedBooks = this.borrowedBooks.filter(b => b.getTitle() != book.getTitle());
        book.returnBook();
        console.log(`${this.name} đã trả: ${book.getTitle()}`);
    }
};

class Library {
    constructor(
        protected books: Book[] = [],
        protected members: Member[] = []
    ) { }

    public addBook(book: Book): void {
        this.books.push(book);
    }

    public addMember(member: Member): void {
        this.members.push(member);
    }

    public listAvailableBooks(): void {
        console.log("\n📚 Danh sách sách có sẵn:");
        for (let i: number = 0; i < this.books.length; i++)
            if (this.books[i].getAvailable() == true)
                console.log("- " + this.books[i].getTitle());
    }
}

// ---------------- Demo ----------------
const lib = new Library();

const b1 = new Book(1, "Clean Code", "Robert C. Martin", 2008, true);
const b2 = new Book(2, "Design Patterns", "GoF", 1994, true);

lib.addBook(b1);
lib.addBook(b2);

const m1 = new Member(1, "Huy");
lib.addMember(m1);

m1.borrow(b1);
m1.borrow(b2);

lib.listAvailableBooks();

m1.return(b1);
lib.listAvailableBooks();

const Node = require("./node");

class SinglyLinkedList{
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    //insert at the beginning
    insertAtbeginning(data){
        this.length+=1;
      if(this.head==null){
        this.head = new Node(data);
        this.tail = this.head;
         return this.head;
      }
      const newNode = new Node(data);
      newNode.next = this.head;
      this.head = newNode;
      return newNode;
    }
    //insert at the end
    insertAtend(data){
        this.length+=1;
        if(this.head==null){
            this.head = new Node(data);
            this.tail = this.head;
            return this.head;
        }
        const newNode = new Node(data);
        this.tail.next = newNode;
        this.tail = this.tail.next
        return this.tail;
    }
    //delete a node {
        //at end
        deletedAtEnd(){
            if(this.isEmpty()){
                console.log("list is already empty");
                return "list is already empty!"
            }
            let temp = this.head;
            let deletedNode = this.tail;
            let cnt = 1;
            while(cnt<this.length-1){
                cnt++;
                 temp = temp.next;
            }
            temp.next = null;
            this.tail = temp;
            temp = null;
            this.length-=1;
            return deletedNode;
        }
        //at beginning
        deleteAtbeginning(){
            if(this.isEmpty()){
                console.log("list is already empty");
                return "list is already empty!"
            }
            let deletedNode = this.head;
            this.head =this.head.next;
            deletedNode.next = null;
            this.length-=1;
            return deletedNode;
        }
        //at indexAt
        deleteAtPosition(index){
            if(this.isEmpty()){
                console.log("list is already empty");
                return "list is already empty!"
            }
            if(index<=0 || index>this.length){
                console.log("Invalied Position!");
                return "Invalied position!"
            }
            if(index==1){
                this.length-=1;
                return this.deleteAtbeginning();
            }
            if(index==this.length){
                this.length-=1;
                return this.deletedAtEnd();
            } 
            let curr = this.head.next;
            let prev = this.head;
            let cnt = 1;
            while(cnt++<index-1){
                prev = curr;
                curr= curr.next;
            }
            let deleteNode = curr;
            prev.next = curr.next;
            curr.next = null;
            prev = null;
            curr = null;

            this.length-=1;
            return [deleteNode,this.head];
        }
    // }
    //print a linkedlist
    printList(){
        if(this.head==null){
            console.log('List Is empty!');
        }
        let temp = this.head;
        while(temp!=null){
            console.log(temp.val);
            temp = temp.next;
        }
    }
    //using 1 base indexing
    //search for a node
    search(target){
        if(this.isEmpty()){
            console.log("List is empty so not possibble to search!");
        }
        if(this.tail.val==target){
            console.log("your searched value present at index:",this.length);
            return true;
        }
        let temp = this.head;
        let count = 0;
        while(temp!=null){
            count++
            if(temp.val==target){
                console.log("your searched value present at index:",count);
               return true;
            }
            temp = temp.next
        }
        console.log("your searched value not present in entire list:");
        return false;
    }
    isEmpty(){
        return this.head==null?true:false;
    }
    showSize(){
        console.log(this.length)
        return this.length;
    }

}



module.exports = SinglyLinkedList;

let obj = {
    name: "kiran",
    age: 40,
    location: "jurong west",
    showInfo: function (age)
    {
        showMessage(this.name + " is " + this.age);
    }
    
};

obj.showInfo(35);
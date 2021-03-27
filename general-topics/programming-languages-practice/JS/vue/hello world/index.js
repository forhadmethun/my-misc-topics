Vue.component('todo-item',{
    template: '<li>This is a todo</li>'
});

Vue.component('todo-item2',{
    props:['todo'],
    template: '<li>{{todo.text}}</li>'
});

var app = new Vue({
   el: "#app",
   data: {
       message: 'Hello Forhad!',
       seen: true,
       todos:
       [
           {text: 'Learn JS'},
           {text: 'Learn Vue'},
           {text: 'Build Awesome Something!!!!'}
       ],
       groceryList: [
           { id: 0, text: 'Vegetables' },
           { id: 1, text: 'Cheese' },
           { id: 2, text: 'Whatever else humans are supposed to eat' }
       ]
   },
    methods: {
        reverseMessage: function () {
            this.message = this.message.split('').reverse().join('')

        }
    }
});


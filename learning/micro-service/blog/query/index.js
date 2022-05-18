const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors'); 
const axios = require('axios'); 

const app = express(); 
app.use(bodyParser.json());
app.use(cors());

const posts = {}

/*
posts === {
    id: 'j13513',
    title: 'A post title',
    comments: [
        { id: 'klasjdfa', contnt: 'comment' }
    ]
}
*/

const handleEvent = (type, data) => {
    if (type === 'PostCreated') {
        const { id, title } = data; 
        posts[id] = { id, title, comments: [] };
    }

    if (type === 'CommentCreated') {
        const { id, content, status, postId } = data; 
        posts[postId].comments.push({ id, content, status })
    }

    if (type === 'CommentUpdated') {
        const { id, content, status, postId } = data; 
        posts[postId].comments.push({ id, content, status })
    }
}; 

app.get('/posts', (req, res) => {
    res.send(posts);
});

app.post('/events', (req, res) => {
    const {type, data} = req.body; 
    handleEvent(type, data);
    res.send({});
});


app.listen(4002, async () => {
    console.log("Listening on port 4002!");

    const res = await axios.get('http://event-bus-srv:4005/events');

    for (let event of res.data) {
        console.log('Processing event: ', event.type);
        handleEvent(event.type, event.data); 
    }

})
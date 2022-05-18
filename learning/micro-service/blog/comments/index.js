const express = require('express'); 
const bodyParser = require('body-parser');
const { randomBytes } = require('crypto');
const cors = require('cors');
const axios = require('axios');

const app = express(); 
app.use(bodyParser.json())
app.use(cors()); 

const commentsByPostId = {}; 

app.get('/posts/:id/comments', (req, res) => {
    const { id } = req.params;
    res.send(commentsByPostId[id]);
});

app.post('/posts/:id/comments', async (req, res) => {
    const commentId = randomBytes(4).toString('hex'); 
    const { content } = req.body;
    const comments = commentsByPostId[req.params.id] || []

    const comment = {
        id : commentId, 
        content, 
        status: 'pending'
    };

   commentsByPostId[req.params.id] = [...comments, comment];

   await axios.post('http://event-bus-srv:4005/events', {
        type: 'CommentCreated', 
        data: {
            ...comment, 
            postId: req.params.id
        }
    });

    res.status(201).send(commentsByPostId[req.params.id])
});

app.post('/events', async (req, res) => {
    console.log('Received Event: ', req.body.type);

    const { type, data} = req.body; 

    if (type === 'CommentModerated') {
        const { postId, id, status } = data; 
        const comments = commentsByPostId[postId]; 
        const comment = comments.find( comment => comment.id === id);
        comment.status = status;

        await axios.post('http://event-bus-srv:4005/events', {
            type: 'CommentUpdated', 
            data: {
                ...comment, 
                postId
            }
        });
    }
});


app.listen(4001, () => {
    console.log('Listening on 4001')
});

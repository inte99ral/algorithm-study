
```js
const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(express.static(path.join(__dirname, 'public')));

// * API 응답 테스트
app.get('/api/test', (req, res) => {
    res.json({
        success: true,
        message: 'Express is working'
    });
});

app.listen(PORT, () => console.log(`Express server running on port ${PORT}`));
```

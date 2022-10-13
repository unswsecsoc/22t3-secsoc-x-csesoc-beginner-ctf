import sqlite3 from 'sqlite3';
import express from 'express';

const BACK = `<br><a href="/">Back</a>`;

const app = express();

const db = new sqlite3.Database(':memory:');
db.serialize();

db.run(`CREATE TABLE users (
  username TEXT NOT NULL,
  password TEXT NOT NULL
)`);

db.run('INSERT INTO users VALUES ("admin", "sUp3rS3curePa$$1735")');

app.use(express.urlencoded({ extended: false }));

app.use(express.static('./static'));

const BLACKLIST = ['UNION', 'OR'];

const checkSuspicious = (inp) => {
  inp = inp.toUpperCase();

  for (const b of BLACKLIST) {
    if (inp.includes(b)) {
      return {
        suspicious: true,
        reason: 'Suspicious phrase found: ' + b,
      };
    }
  }

  return {
    suspicious: false,
  };
};

app.post('/login', (req, res) => {
  if (typeof req.body.user !== 'string' || typeof req.body.pass !== 'string') {
    res.send('Invalid params' + BACK);
    return;
  }

  const { user, pass } = req.body;

  const userSus = checkSuspicious(user);
  const passSus = checkSuspicious(pass);
  if (userSus.suspicious) {
    res.send(`Looks like you're trying something naughty! ${userSus.reason}`);
    return;
  }
  if (passSus.suspicious) {
    res.send(`Looks like you're trying something naughty! ${passSus.reason}`);
    return;
  }

  const query = `SELECT username FROM users WHERE username='${user}' AND password='${pass}'`;

  db.get(query, [], (err, row) => {
    if (err) {
      res.send(`Error running query <code>${query}</code><br>` + err + BACK);
      return;
    }
    if (row) {
      res.send(
        'Welcome! The flag is BEGINNER{sqL_inj3ction_15_a_cl4551c_caf0ab}'
      );
      return;
    }
    res.send('Invalid username or password' + BACK);
  });
});

app.listen(8000, () => {
  console.log('Listening on port 8000');
});

console.log('wow');

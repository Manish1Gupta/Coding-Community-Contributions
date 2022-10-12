"use strict";

let question1 = {
  question: "What pointer stores ?",
  option: ["value", "address", "null", "undefined"],
  state: false,
  correctOption: 1,
};
let question2 = {
  question: "What is data encapsulation ?",
  option: ["data hiding", "data revealing", "data mining", "data storing"],
  state: false,
  correctOption: 0,
};
let question3 = {
  question: "What is dangling pointer ?",
  option: [
    "pointing to heap",
    "pointing to stack",
    "pointing to deleted memory",
    "pointing to uninitilzed",
  ],
  state: false,
  correctOption: 2,
};
let question4 = {
  question: "What is the maximum size of the array on stack?",
  option: ["10^4", "10^5", "10^6", "10^7"],
  state: false,
  correctOption: 2,
};
let question5 = {
  question: "Which operator can not be overloaded?",
  option: ["+", "->", " .", "!"],
  state: false,
  correctOption: 2,
};

let questions = [question1, question2, question3, question4, question5];

let totalCorrect = 0;
questions.forEach((question) => {
  let userAnswer = +prompt(`${question.question}\n
  1.${question.option[0]} 
  2.${question.option[1]} 
  3.${question.option[2]} 
  4.${question.option[0]}`);

  --userAnswer == question.correctOption && totalCorrect++;
});

alert(`Your total correct answers are : ${totalCorrect}\n`);

# "You Bet Your Life" Game Module


This lab was a 2-week project where I was building a module for a game inspired by the old TV game show "You Bet Your Life," hosted by the legendary Groucho Marx.

## Team Collaboration
 - You have the option to work individually, or in a team of 2 (pair programming is encouraged).
 - If working in a team, submit the same code from both members, and provide team member names in comments.
 - No extra credit for individual work.
 - I decided to do this project by myself.

## Game Overview
 - In this project, we will start by building a module that waits for a secret word to be mentioned. Participants will type words or sentences, and the module will check if the secret word is included.

## Process #2 - "groucho"

 - The process runs initially with the secret word as the command line variable.
 - Acknowledges the secret word with the message: "Today's secret woid is... say the word and win 100 bucks."
 - Normalizes the secret word to either upper-case or lower-case (you can choose when to normalize).
 - Waits for contestants to type a word or sentence, accepting the input via a FIFO.
 - If the typed string DOES NOT contain the secret word, sends "NO" back to the contestant process via the FIFO.
 - If the typed string DOES contain the secret word, sends back: "Hooray for Captain Spaulding the African Explorer...did someone call me Schnorer... Hooray, hooray, hooray!!! You just said the secret word, and you have won $100!"
 - Once the secret word has been heard, the "groucho" process terminates.

## Process #1 - "contestant"
 - Prompts the contestant to type in a string.
 - Accepts any string up to 80 characters.
 - Sends this string to the "groucho" process via the FIFO for evaluation (you need to decide where to normalize the text).
 - Waits for a response from the "groucho" process.
 - If the "NO" string is received via the FIFO from the "groucho" process, the contestant is prompted for another input without mentioning the incorrect guess.
 - If anything other than "NO" is received, prints out the message received.
 - Once the congratulatory message is received, the "contestant" process can terminate.

## Additional Features
 - Disabled CTRL-C and CTRL-Z for both processes.
 - If either interrupt is received 3 times, re-enable the interrupt and allow it to take its normal action.


## Getting Started
 - Follow these instructions to set up and run the "You Bet Your Life" game module:

1.) Clone the repository to your local machine.
2.) Navigate to the project directory.
3.) Run the "groucho" process with the secret word as a command line variable.
4.) Run the "contestant" process for each contestant.


## Usage
 - Participants can type words or sentences to interact with the game module.
 - The "groucho" process will respond based on whether the secret word is mentioned.

## Known Issues
- The current implementation does not display the "Captain Spaulding..." message as requested.
- The secret word must be in small letters for proper recognition (The secret word was accepted in any format).

## Acknowledgments
 - "You Bet Your Life" TV game show.
 - Groucho Marx - a legend in the entertainment industry.

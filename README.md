# Compiler Design Theory 

## Lexical Analysis

### Identify different types of tokens 

There are a lot of tokens used in c, but I'll will stick to these 

1) Identifiers 
    - identifiers
    - number

2) Keywords

    - if 
    - else 
    - while 
    - continue
    - break
    - return 

    - int 
    - float 
    - char 

3) Operators

    - add (+)
    - sub (-)
    - mul (*)
    - div (/)
    - mod (%)

    - and (&&)
    - or (||)
    - not (!)

    - assign (=)
    
    - equals (==)
    - not equals (!=)
    - greater than or equals (>=)
    - less than or equals (<=)
    - grearter than (>)
    - less then (<)

4) Punctuations 
    
    - open para (()
    - closed para ())
    - open braket ([)
    - close braket (])
    - open brace ({)
    - close brace (})
    - comma (,)
    - semi-colon (;)

### State machines 

-> (input state) ---first character--> (first character state) ---lambda transition--> (character specific state machine)



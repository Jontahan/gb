# gb

This is my attempt at creating a nice and compact Game Boy emulator in C++.
I do this for fun, but if I pull off a structured and clean end result this can be used
as a reference for others who want to do the same. After working on this for only a couple of hours 
I have realised that writing an emulator is one of the most effective ways to get your hands
dirty with low level/limited hardware programming. I am learning stuff on the go here, so things might change drastically over time.

After working on this for a while I realize that I am writing a soft gb debugger as well, and it would be a waste to throw that away when the emulator works properly, so I guess this is becoming more of a open source no$gba-ish thing. 

# Current state:
- More than half of the arithmetic operations are implemented and mapped.
- Ugly temporary jumping functionality so I can trace ROM programs by iteration.
- Somewhat of a framework/skeleton for generalization of most operations.
- Graphic display is done, vram is empty so when the processor works fine, everything should.

# Features for version 1.0
- Should run all ROMs without fatalities
- Might or might not play sounds, I'll see when that time comes
- Should provide some fun meta-tools/insights, not unlike NO$GMB

# Beyond version 1.0
- Game Boy Color ROM support
- Scripting & running game manipulation
- Streaming (simply because it's so easy in this situation)

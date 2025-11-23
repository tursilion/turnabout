The noise makes synthesis suck, the raw Ai voice without the boom isn't very powerful. We'll live with samples, but
since they are loud we should be able to use best-match rather than my Dragon's Lair mapping.

I'll also convert to 8192hz. All samples are under 1 second in length, so that's the highest rate we can guarantee
will fit in one 4096 page (at 4 bits per sample). Since it's a dedicated playback engine we can afford the bitshifts.

---

https://www.openai.fm/

--
Accent/Affect: excited lawyer, Phoenix Wright

Tone: Insistent, somewhat excited interjection

Pacing: Fast, forceful, strong emphasis

Emotion: Excited, powerful, interjection

Pronunciation: Clear english, shouted
--
Objection!!
--

Convert to 8000hz, 8 bit mono before running TI audioconvert to shift down to nibbles for playback.
Using Eric's ConvertLpcToWav (in VideoTools, use Debian), need 16 bit 8000hz.



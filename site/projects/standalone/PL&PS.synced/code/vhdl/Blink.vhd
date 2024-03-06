library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;       -- Operations: addition/..

-- ------------------------------------------ --
-- =                 Entity                 = --
-- ------------------------------------------ --
-- Description: Functions:
--      Blink PL(RGB).
--      Pause with PS(button).
--      PL(BUZZ) with PS(button).
--      Output CLK(downscaled) to blink PS(LED1/LED2).
-- (Downscaler method):
--      (Scale at around 1Hz).
--      Count up to CLK's frequency. Keep the MSbits.
-- -
entity Blink is
    Generic(
        N: natural := 27);  -- Primitive downscaling
    Port(
        CLK        : in  STD_LOGIC;
        RESET      : in  STD_LOGIC;
        BUTTON     : in  STD_LOGIC;
    	RGB        : out STD_LOGIC_VECTOR(2 downto 0);
    	BUZZER     : out STD_LOGIC;
    	CLK_out    : out STD_LOGIC);
end Blink;

-- ------------------------------------------------ --
-- =                 Architecture                 = --
-- ------------------------------------------------ --
architecture Behavioral of Blink is
    signal ticks: std_logic_vector(N - 1 downto 0) := (others => '0'); -- downscale to ~1b0Hz
begin
    -- Downscale: Count up to 2**N. Output around ~1Hz.
    -- -
    process (CLK, RESET, BUTTON)
        variable t: natural range 2**N - 1 downto 0 := 0;
    begin
        ticks <= std_logic_vector(to_unsigned(t, N));
        if rising_edge(CLK) then
            -- Pause on BUTTON(0) (pressed).
            -- (Buttons use pull-up (?)). [Thus, their values are inverted]..
            -- (Let's [just] say they are active low:).
            -- -
            if BUTTON = '1' then
                t := t + 1;
            else
                -- Pause [on active low].
                -- -
            end if;
        end if;
    end process;

    -- Blink around ~1Hz ±1Hz, utilizing MSBs.
    -- -
    RGB     <= ticks(N - 1 downto N - 3);
    BUZZER  <= not BUTTON;
    CLK_out <= ticks(N - 1);
end Behavioral;

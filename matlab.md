```matlab
function sciagawka
    format short;
    co3_max_100 = 3:3:100; % generuje wektor, i.e. [3, 6 ..]
    costam_pi = linspace(1, 2*pi, 12);

    costam_pi(3); % indexing, starts w/ 1
    els3_6 = costam_pi(3:6);
    els_wo_last = costam_pi(1:end-1);
    els_by_idx_1_5_6 = costam_pi([1 5 6]);
    costam_pi(costam_pi < 2);
    costam(costam_pi < 2) = 0; % zastąp liczby spełniające warunek

    ey = eye(3) * 1.3;% macierz jednostkowa
    zeros(3); ones(2);

    for i=1:4
        j = 0;
        while (j ~= 3)
            j = j + 1;
        end
    end
    [ret1, ret2] =nazwa_funkcji(1, 2);
    % disp(ret2);
    % plot(costam_pi, "k.");
    xlabel('Czas t [s]'); ylabel('U [V]');
    title("hello world!");
    % split 2 rows, 1 col, be 2nd
    subplot(2,1,2), plot(costam_pi(1:6), "k.");
    subplot(2,1,1), plot(costam_pi, "k*");
end

function [zwracana1, zwracana2] = nazwa_funkcji(argument1, argument2)
    zwracana1 = argument1 + argument2;
    zwracana2 = argument1 * argument2;
end
```

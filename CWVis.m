errors = load("C:\Users\BlackBow\Desktop\Lab_and_practice\8_semestr\EM_coursework\data\results\errors.txt");
results = load("C:\Users\BlackBow\Desktop\Lab_and_practice\8_semestr\EM_coursework\data\results\results.txt");
cocomo = load("C:\Users\BlackBow\Desktop\Lab_and_practice\8_semestr\EM_coursework\data\cocomo_test.txt");
ls = load("C:\Users\BlackBow\Desktop\Lab_and_practice\8_semestr\EM_coursework\data\test.txt");
s = size(errors);
xs = 1:1:s(1);
figure;
plot(xs, errors(:,1));
hold on
plot(xs, errors(:,2));
plot(xs, errors(:,3));
legend("�����������","�������","������������")
xlabel("���������")
ylabel("������")
title("������ ��������")

figure;
s = size(results);
xs = 1:1:s(1);
plot(xs, results(:,1));
hold on
plot(xs, cocomo);
plot(xs, results(:,2));
legend("�������� ������","������","��������")
xlabel("����� ������")
ylabel("������")
title("������ ������")

% figure;
% s = size(results);
% xs = 1:1:s(1);
% plot(ls(:,1), results(:,1), "o");
% hold on
% plot(ls(:,1), results(:,2), "*");
% legend("�������� ������","��������")
% xlabel("����� ����� ����")
% ylabel("������")
% title("����������� ������������")
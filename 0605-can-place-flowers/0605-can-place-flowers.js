/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  const flowerbedLength = flowerbed.length;

  if (n === 0 || flowerbedLength === 0) return true; // Handle empty cases

  for (let i = 0; i < flowerbedLength; i++) {
    const canPlant = (
      (i === 0 || flowerbed[i - 1] === 0) &&
      flowerbed[i] === 0 &&
      (i === flowerbedLength - 1 || flowerbed[i + 1] === 0)
    );

    if (canPlant) {
      n--;
      flowerbed[i] = 1;
      if (n === 0) return true; // Early return
    }
  }

  return false;
};

// tc -> O(n)
// sc -> O(1)
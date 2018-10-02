class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> intersect = new ArrayList<Integer>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0;
        int j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                intersect.add(nums1[i]);
                i++;
                j++;
            }
        }

        int[] ret = new int[intersect.size()];
        for (int k = 0; k < intersect.size(); k++) {
            ret[k] = intersect.get(k);
        }

        return ret;
    }
}